import sys
from os.path import dirname, pardir, realpath, sep

sys.path.append(
    dirname(realpath(__file__)) + sep + pardir + sep + pardir + sep + "partials"
)

import slang_gen

sub = {"int": "int32_t", "uint": "uint32_t", "byte": "uint8_t"}

with open("matrix.h.in", "r") as f:
    template = f.read()
with open("matrix.i.in", "r") as f:
    template_swig = f.read()

for type in slang_gen.scalar_types:
    name = type
    if type in sub:
        type = sub[type]
    is_int = type in slang_gen.int_types
    is_bool = "bool" in type

    for X in range(2, 5):
        for Y in range(2, 5):
            with open(f"{name}{X}x{Y}.h", "w") as f:
                f.write(
                    template.replace("{type}", type)
                    .replace("{name}", name)
                    .replace("{X}", f"{X}").replace("{Y}", f"{Y}")
                    .replace("{is_int}", "true" if is_int else "false")
                    .replace("{is_bool}", "true" if is_bool else "false")
                )
            with open(f"{name}{X}x{Y}.i", "w") as f:
                f.write(
                    template_swig.replace("{type}", type)
                    .replace("{name}", name)
                    .replace("{X}", f"{X}").replace("{Y}", f"{Y}")
                    .replace("{is_int}", "true" if is_int else "false")
                    .replace("{is_bool}", "true" if is_bool else "false")
                )
