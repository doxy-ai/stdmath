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

            out += f"inline static stdmath_{name}{N} stdmath_{name}{N}_{''.join(p)}_value(stdmath_{name}{N} v, stdmath_{name}{len(p)} value) " + "{ "
            out += "; ".join([f"v.{c} = value.{ordered[i]}" for i, c in enumerate(p)])
            out += "; return v; }\n"
    else:
        for p in permutations:
            if len(p) == 1: continue
            out += f"\tstdmath_{name}{len(p)} {''.join(p)};\n"

            out += f"\tstdmath_{name}{len(p)} get_{''.join(p)}() "
            out += "{ return {self->" + ",self->".join(p) + "}; }\n"

            out += f"\tstdmath_{name}{N} set_{''.join(p)}(stdmath_{name}{len(p)} value) " + "{ "
            out += "; ".join([f"self->{c} = value.{ordered[i]}" for i, c in enumerate(p)])
            out += "; return *self; }\n\n"
    return out


sub = {"int": "int32_t", "uint": "uint32_t", "byte": "uint8_t"}

with open("type1.h.in", "r") as f:
    template1 = f.read()
with open("type2.h.in", "r") as f:
    template2 = f.read()
with open("type3.h.in", "r") as f:
    template3 = f.read()
with open("type4.h.in", "r") as f:
    template4 = f.read()
with open("vector.i.in", "r") as f:
    template_swig = f.read()

for type in slang_gen.scalar_types:
    name = type
    if type in sub:
        type = sub[type]
    is_int = type in slang_gen.int_types
    is_bool = "bool" in type

    with open(f"{name}1.h", "w") as f:
        permutations = power_set(["x"])
        swizzles = generate_swizzles(name, 1, permutations)
        f.write(
            template1.replace("{type}", type)
            .replace("{name}", name)
            .replace("{swizzles}", swizzles)
            .replace("{is_int}", "true" if is_int else "false")
            .replace("{is_bool}", "true" if is_bool else "false")
        )
    with open(f"{name}1.i", "w") as f:
        swizzles = generate_swizzles(name, 1, permutations, True)
        f.write(
            template_swig.replace("{type}", type)
            .replace("{name}", name)
            .replace("{swizzles}", swizzles)
            .replace("{N}", "1")
            .replace("{is_int}", "true" if is_int else "false")
            .replace("{is_bool}", "true" if is_bool else "false")
        )

    with open(f"{name}2.h", "w") as f:
        permutations = power_set(["x", "y"])
        swizzles = generate_swizzles(name, 2, permutations)
        f.write(
            template2.replace("{type}", type)
            .replace("{name}", name)
            .replace("{swizzles}", swizzles)
            .replace("{is_int}", "true" if is_int else "false")
            .replace("{is_bool}", "true" if is_bool else "false")
        )
    with open(f"{name}2.i", "w") as f:
        swizzles = generate_swizzles(name, 2, permutations, True)
        f.write(
            template_swig.replace("{type}", type)
            .replace("{name}", name)
            .replace("{swizzles}", swizzles)
            .replace("{N}", "2")
            .replace("{is_int}", "true" if is_int else "false")
            .replace("{is_bool}", "true" if is_bool else "false")
        )

    with open(f"{name}3.h", "w") as f:
        permutations = power_set(["x", "y", "z"])
        swizzles = generate_swizzles(name, 3, permutations)
        f.write(
            template3.replace("{type}", type)
            .replace("{name}", name)
            .replace("{swizzles}", swizzles)
            .replace("{is_int}", "true" if is_int else "false")
            .replace("{is_bool}", "true" if is_bool else "false")
        )
    with open(f"{name}3.i", "w") as f:
        swizzles = generate_swizzles(name, 3, permutations, True)
        f.write(
            template_swig.replace("{type}", type)
            .replace("{name}", name)
            .replace("{swizzles}", swizzles)
            .replace("{N}", "3")
            .replace("{is_int}", "true" if is_int else "false")
            .replace("{is_bool}", "true" if is_bool else "false")
        )

    with open(f"{name}4.h", "w") as f:
        permutations = power_set(["x", "y", "z", "w"])
        swizzles = generate_swizzles(name, 4, permutations)
        f.write(
            template4.replace("{type}", type)
            .replace("{name}", name)
            .replace("{swizzles}", swizzles)
            .replace("{is_int}", "true" if is_int else "false")
            .replace("{is_bool}", "true" if is_bool else "false")
        )
    with open(f"{name}4.i", "w") as f:
        swizzles = generate_swizzles(name, 4, permutations, True)
        f.write(
            template_swig.replace("{type}", type)
            .replace("{name}", name)
            .replace("{swizzles}", swizzles)
            .replace("{N}", "4")
            .replace("{is_int}", "true" if is_int else "false")
            .replace("{is_bool}", "true" if is_bool else "false")
        )
