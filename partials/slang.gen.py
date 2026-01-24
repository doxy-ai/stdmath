def generate_hlsl_types():
	scalar_types = [
		"bool",
		"int",
		"uint",
		"float",
		"double",
		"byte",
	]

	sub = {
		"int": "i32",
		"uint": "u32",
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


with open("slang.usings.partial", "w") as f: 
	types = generate_hlsl_types()
	f.write("\n".join(types))
