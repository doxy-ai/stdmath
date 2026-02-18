scalar_types = [
	"bool",
	"int",
	"uint",
	"float",
	"double",
	"byte",
	"radian",
	"degree"
]

int_types = [
	"int", "uint", "byte"
]

def generate_hlsl_types():
	sub = {
		"int": "i32",
		"uint": "u32",
		"byte": "u8"
	}

	vector_sizes = [1, 2, 3, 4]
	matrix_sizes = [2, 3, 4]

	vector_types = []
	matrix_types = []

	# Generate vector types (e.g. float3, int4)
	for base in scalar_types:
		for size in vector_sizes:
			substitution = sub.get(base, base)
			vector_types.append(f"export using {base}{size} = vector<{substitution}, {size}>;")

	# Generate matrix types (e.g. float4x4, double3x2)
	for base in scalar_types:
		for rows in matrix_sizes:
			for cols in matrix_sizes:
				substitution = sub.get(base, base)
				matrix_types.append(f"export using {base}{rows}x{cols} = matrix<{substitution}, {rows}, {cols}>;")

	return vector_types + [''] + matrix_types

if __name__ == "__main__":
	with open("slang.usings.partial", "w") as f: 
		types = generate_hlsl_types()
		f.write("\n".join(types))

	# with open("slang.swig.partial", "w") as f:
	# 	types = [t[12:].split("=") for t in types]
	# 	# print(types)
	# 	for i in range(0, len(types)):
	# 		try:
	# 			type_name = types[i][0].strip()
	# 			c_name = types[i][1].strip()[:-1]

	# 			types[i] = (f"%template({type_name}) {c_name};\n"\
	# 				+ f"%template(__{type_name}_ops) operators_crtp<{c_name}>;\n"\
	# 				+ f"%template(__{type_name}_comps) comparison_operators_crtp<{c_name}, vector<bool, {c_name.split(",")[1].strip()}>;\n")\
	# 				.replace("<byte", "<uint8_t")
	# 		except: types[i] = "".join(types[i])
			
	# 	print(types)
	# 	f.write("\n".join(types))
