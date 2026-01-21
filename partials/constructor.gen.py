def compositions(n):
    if n == 0:
        return [[]]
    result = []
    for i in range(1, n + 1):
        for tail in compositions(n - i):
            result.append([i] + tail)
    return result

def build_constructors(compositions):
    out = "template<typename To>\nvector(const vector<To, N>& o) {\n\tauto range = std::views::iota(size_t{0}, N);\n#ifdef __clang__\n\tstd::for_each(range.begin(), range.end(), [&](size_t i) {\n#else\n\tstd::for_each(std::execution::par_unseq, range.begin(), range.end(), [&](size_t i) {\n#endif\n\t\tdata[i] = o[i];\n\t});\n}\n\n"
    out += "constexpr vector() {}\nvector(const vector&) = default;\nconstexpr vector(vector&&) = default;\nconstexpr vector& operator=(const vector&) = default;\nconstexpr vector& operator=(vector&&) = default;\n"
    for comp in compositions:
        if len(comp) <= 1: continue
        out += "vector("
        for i, size in enumerate(comp):
            out += f"const vector<T, {size}>& _{i}"
            if i < len(comp) - 1: out += ", " 
        out += "): data({"
        for i, size in enumerate(comp):
            for j in range(0, size):
                out += f"_{i}[{j}]"
                if j < size - 1: out += ", " 
            if i < len(comp) - 1: out += ", " 
        out += "}) {}\n"
    return out
        
for i in range(1, 4 + 1):
    with open(f"vec{i}.constructors.partial.gen", "w") as f: f.write(build_constructors(compositions(i)))