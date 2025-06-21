def compositions(n):
    if n == 0:
        return [[]]
    result = []
    for i in range(1, n + 1):
        for tail in compositions(n - i):
            result.append([i] + tail)
    return result

def build_constructors(compositions):
    out = "template<typename To>\r\nvec(const vec<To, N>& o) {\r\n\tauto range = std::views::iota(size_t{0}, N);\r\n\tstd::for_each(std::execution::par_unseq, range.begin(), range.end(), [&](size_t i) {\r\n\t\tdata[i] = o[i];\r\n\t});\r\n}\n\n"
    out += "vec() {}\nvec(const vec&) = default;\nvec(vec&&) = default;\nvec& operator=(const vec&) = default;\nvec& operator=(vec&&) = default;\n"
    for comp in compositions:
        if len(comp) <= 1: continue
        out += "vec("
        for i, size in enumerate(comp):
            out += f"const vec<T, {size}>& _{i}"
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