#!/usr/bin/env python3

import os
import sys
from pathlib import Path


def generate_aggregate_header(root_dir: Path, output_file: Path):
    swig = output_file.suffix == ".i"
    root_dir = root_dir.resolve()
    output_file = output_file.resolve()

    headers = []

    for path in root_dir.rglob("*.i" if swig else "*.h"):
        # Skip the output file itself
        if path.resolve() == output_file:
            continue
        headers.append(path)

    # Sort for deterministic output
    headers.sort()

    with output_file.open("w") as f:
        guard = output_file.stem.upper() + "_INCLUDED"
        if(swig): 
            f.write(f"%module {output_file.stem}\n\n")
            f.write("%{\n")
            f.write(f"import stdmath.slang;\n")
            f.write(f"import stdmath.c;\n")
            f.write("%}\n\n")
        else:
            f.write(f"#ifndef {guard}\n")
            f.write(f"#define {guard}\n\n")
        
        for header in headers:
            rel_path = header.relative_to(output_file.parent)
            # Use forward slashes for portability
            include_path = rel_path.as_posix()
            f.write(f'{"%" if swig else "#"}include "{include_path}"\n')

        if not swig: 
            f.write(f"\n// NOTE: we include the headers again so that implementations which rely on other headers being available can be materialized\n")
            f.write(f"#ifdef {output_file.stem.upper()}_IMPLEMENTATION\n")
            for header in headers:
                rel_path = header.relative_to(output_file.parent)
                # Use forward slashes for portability
                include_path = rel_path.as_posix()
                f.write(f'#include "{include_path}"\n')
            f.write(f"\n#endif //{output_file.stem.upper()}_IMPLEMENTATION\n")
            
            f.write("\n#endif\n")

    print(f"Generated {output_file} with {len(headers)} includes.")


if __name__ == "__main__":
    if len(sys.argv) != 3:
        print("Usage: python generate_headers.py <root_dir> <output_file>")
        sys.exit(1)

    root = Path(sys.argv[1])
    output = Path(sys.argv[2])

    generate_aggregate_header(root, output)
