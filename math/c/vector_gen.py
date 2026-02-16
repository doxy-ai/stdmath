import sys
from os.path import dirname, pardir, realpath, sep

sys.path.append(
    dirname(realpath(__file__)) + sep + pardir + sep + pardir + sep + "partials"
)

import slang_gen
from swizzle_gen import power_set


def generate_swizzles(name, N, permutations, swig = False):
    ordered = ["x", "y", "z", "w"]
    out = ""
    if not swig:
        for p in permutations:
            out += f"inline static stdmath_{name}{len(p)} stdmath_{name}{N}_{''.join(p)}(stdmath_{name}{N} v) "
            out += "{ return {v." + ",v.".join(p) + "}; }\n"
            out += f"inline static stdmath_{name}{len(p)} stdmath_{name}{N}_{''.join(p)}_get(stdmath_{name}{N}* p) "
            out += f"{{ return stdmath_{name}{N}_{''.join(p)}(*p); }}\n"

            out += f"inline static stdmath_{name}{N} stdmath_{name}{N}_{''.join(p)}_set(stdmath_{name}{N}* p, stdmath_{name}{len(p)} value) " + "{ "
            out += "; ".join([f"p->{c} = value.{ordered[i]}" for i, c in enumerate(p)])
            out += "; return *p; }\n"
    else:
        for p in permutations:
            if len(p) == 1: continue
            out += f"\tstdmath_{name}{len(p)} {''.join(p)};\n"

    return out


sub = {"int": "int32_t", "uint": "uint32_t", "byte": "uint8_t"}

with open("vector.h.in", "r") as f:
    template = f.read()
with open("vector.i.in", "r") as f:
    template_swig = f.read()

for type in slang_gen.scalar_types:
    name = type
    if type in sub:
        type = sub[type]
    is_int = type in slang_gen.int_types
    is_bool = "bool" in type

    for N in range(1, 5):
        with open(f"{name}{N}.h", "w") as f:
            permutations = power_set(["x", "y", "z", "w"][0:N])
            swizzles = generate_swizzles(name, N, permutations)
            f.write(
                template.replace("{type}", type)
                .replace("{name}", name)
                .replace("{swizzles}", swizzles)
                .replace("{N}", f"{N}")
                .replace("{is_int}", "true" if is_int else "false")
                .replace("{is_bool}", "true" if is_bool else "false")
            )
        with open(f"{name}{N}.i", "w") as f:
            f.write(
                template_swig.replace("{type}", type)
                .replace("{name}", name)
                .replace("{swizzles}", generate_swizzles(name, N, permutations, True))
                .replace("{N}", f"{N}")
                .replace("{is_int}", "true" if is_int else "false")
                .replace("{is_bool}", "true" if is_bool else "false")
            )
