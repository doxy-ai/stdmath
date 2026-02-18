import sys
from os.path import dirname, pardir, realpath, sep

sys.path.append(
    dirname(realpath(__file__)) + sep + pardir + sep + pardir + sep + "partials"
)

import slang_gen
from swizzle_gen import power_set



with open("angle.h.in", "r") as f:
    template = f.read()
with open("angle.i.in", "r") as f:
    template_swig = f.read()

for type in ["radian", "degree"]:
    name = type
    is_radian = name == "radian"

    for N in range(1, 5):
        with open(f"gen/{name}.h", "w") as f:
            f.write(
                template.replace("{type}", type)
                .replace("{name}", name)
                .replace("{name_first_letter}", name[0])
                .replace("{is_radian}", "true" if is_radian else "false")
            )
        with open(f"gen/{name}.i", "w") as f:
            f.write(
                template_swig.replace("{type}", type)
                .replace("{name}", name)
                .replace("{name_first_letter}", name[0])
                .replace("{is_radian}", "true" if is_radian else "false")
            )
