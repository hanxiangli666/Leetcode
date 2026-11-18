import numpy as np

from ai.common.gradcheck import grad_check, numerical_grad


def test_square_sum():
    x = np.random.randn(3, 4)
    g = numerical_grad(lambda v: np.sum(v ** 2), x.copy())
    assert np.allclose(g, 2 * x, atol=1e-6)


def test_sin_sum():
    x = np.random.randn(5)
    g = numerical_grad(lambda v: np.sum(np.sin(v)), x.copy())
    assert np.allclose(g, np.cos(x), atol=1e-6)


def test_catches_wrong_grad():
    x = np.random.randn(4)
    ok, _ = grad_check(lambda v: np.sum(v ** 3), x, 3 * x ** 2)
    assert ok
    ok, _ = grad_check(lambda v: np.sum(v ** 3), x, 2 * x ** 2)  # 故意写错
    assert not ok


def test_x_is_restored():
    x = np.random.randn(2, 2)
    before = x.copy()
    numerical_grad(lambda v: np.sum(v), x)
    assert np.array_equal(x, before)
