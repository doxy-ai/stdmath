import sys
from os.path import dirname, pardir, realpath, sep

sys.path.append(
	dirname(realpath(__file__)) + sep + pardir + sep + pardir + sep + "partials"
)

import slang_gen
from swizzle_gen import power_set



with open("color.h.in", "r") as f:
	template = f.read()
with open("color.i.in", "r") as f:
	template_swig = f.read()

for name in ["color32", "color8"]:
	is_color8 = name == "color8"
	type = "uint8_t" if is_color8 else "float"
	backing = "byte4" if is_color8 else "float4"

	for N in range(1, 5):
		with open(f"gen/{name}.h", "w") as f:
			f.write(
				template.replace("{type}", type)
				.replace("{name}", name)
				.replace("{backing}", backing)
				.replace("{is_color8}", "true" if is_color8 else "false")
			)
		with open(f"gen/{name}.i", "w") as f:
			f.write(
				template_swig.replace("{type}", type)
				.replace("{name}", name)
				.replace("{backing}", backing)
				.replace("{is_color8}", "true" if is_color8 else "false")
			)
