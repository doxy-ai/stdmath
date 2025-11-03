
import itertools

def power_set(arr):
	n = len(arr)
	result = []

	# Generate subsets of all lengths from 2 to n
	for r in range(1, n + 1):
		# For each subset length r, generate all combinations with replacement
		combos = itertools.product(arr, repeat=r)
		result.extend(combos)

	return result

def generate_swizzles(permutations, address_of = False):
	out = ""
	for p in permutations:
		out += f"swizzle<T, {len(p)}> {"_" if len(p) == 1 else ""}{''.join(p)}() "
		out += "{ return {" + ("&" if address_of else "") + (",&" if address_of else ",").join(p) + "}; }\n"

		out += f"const swizzle<T, {len(p)}> {"_" if len(p) == 1 else ""}{''.join(p)}() const "
		out += "{ return {" + ("(T*)&" if address_of else "") + (",(T*)&" if address_of else ",").join(p) + "}; }\n"
	return out


permutations = power_set(["x", "y", "z", "w"])
with open("vec4.swizzles.partial.gen", "w") as f: f.write(generate_swizzles(permutations))
with open("vec4.swizzles.address_of.partial.gen", "w") as f: f.write(generate_swizzles(permutations, True))

permutations = power_set(["x", "y", "z"])
with open("vec3.swizzles.partial.gen", "w") as f: f.write(generate_swizzles(permutations))
with open("vec3.swizzles.address_of.partial.gen", "w") as f: f.write(generate_swizzles(permutations, True))

permutations = power_set(["x", "y"])
with open("vec2.swizzles.partial.gen", "w") as f: f.write(generate_swizzles(permutations))
with open("vec2.swizzles.address_of.partial.gen", "w") as f: f.write(generate_swizzles(permutations, True))

permutations = power_set(["x"])
with open("vec1.swizzles.partial.gen", "w") as f: f.write(generate_swizzles(permutations))
with open("vec1.swizzles.address_of.partial.gen", "w") as f: f.write(generate_swizzles(permutations, True))

