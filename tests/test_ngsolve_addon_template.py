def test_import():
    # you need to import ngsolve before importing the extension
    # such that all runtime dependencies are loaded
    import ngsolve
    import quickmark


def test_ComputeXStar():
    import ngsolve
    import quickmark.quickmark as quickmark
    import numpy as np
    
    _list = np.random.uniform( size= 10**3)

    perc = 0.3
    xstar = quickmark.quickmark.ComputeXStar(_list,0.3)
    upper = _list>= xstar
    assert( np.sum(_list[upper])/np.sum(_list) >= perc )



