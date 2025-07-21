# QuickMark python wrapper
The original code is can be found in:

    DÖRFLER MARKING WITH MINIMAL CARDINALITY IS A LINEAR COMPLEXITY PROBLEM
    
    CARL-MARTIN PFEILER AND DIRK PRAETORIUS


## installing the addon project

Quick install: install the addon package directly with pip from git:

    python -m pip install  git+https://github.com/EdoardoBonetti/QuickMark.git

**Alternative** needed for self-compiled NGSolve

    python -m pip install scikit-build-core pybind11_stubgen toml
    python -m pip install --no-build-isolation git+https://github.com/EdoardoBonetti/QuickMark.git


test it:

    python -m afem.demos.exploremesh

Step-by-step installation:

simple step-by-step installation using pip:

    git clone git+https://github.com/EdoardoBonetti/QuickMark.git
    cd ngsolve-addon-template
    python -m pip install --no-build-isolation .

alternative step-by-step installation using `cmake`:

    git clone https://github.com/EdoardoBonetti/QuickMark.git
    cd ngsolve-addon-template
    mkdir build
    cd build
    cmake ..
    make -j4 install

## Troubleshooting

### Problem
Error in gihub actions when building Linux package:

```
    ImportError: /lib64/libstdc++.so.6: version `GLIBCXX_3.4.20' not found
```

### Solution
Update `pyproject.toml` by adding the following line to the `[tool.cibuildwheel]` section:

```toml
[tool.cibuildwheel]
manylinux-x86_64-image = "manylinux_2_28"
```

Some more NGSolve addons you can find here:
  * https://github.com/TUWien-ASC/NGS-myfe (including vs-code instructions)
