"""关卡 0.2 / 0.3：数值梯度与梯度检查。

后面每一关写完 backward，都用这里的 grad_check 验证。
"""
import numpy as np


def numerical_grad(f, x, h=1e-5):
    """用中心差分估计标量函数 f 在 x 处的梯度。

    f: 接收一个与 x 同形状的数组，返回一个标量
    x: 任意形状的 float64 数组（会被临时修改，结束时复原）
    返回: 与 x 同形状的梯度数组
    """
    grad = np.zeros_like(x, dtype=np.float64)
    it = np.nditer(x, flags=["multi_index"])
    while not it.finished:
        idx = it.multi_index
        old = x[idx]

        x[idx] = old + h
        f_plus = f(x)
        x[idx] = old - h
        f_minus = f(x)
        x[idx] = old  # 复原，否则会影响下一个元素

        # TODO(James): 关键一行，用 f_plus、f_minus、h 写出中心差分
        raise NotImplementedError("写出中心差分公式")
        # grad[idx] = ...

        it.iternext()
    return grad


def rel_error(a, b, eps=1e-12):
    """逐元素相对误差的最大值。"""
    a, b = np.asarray(a, dtype=np.float64), np.asarray(b, dtype=np.float64)
    return float(np.max(np.abs(a - b) / np.maximum(eps, np.abs(a) + np.abs(b))))


def grad_check(f, x, analytic_grad, tol=1e-6):
    """比较解析梯度和数值梯度，返回 (是否通过, 相对误差)。"""
    num = numerical_grad(f, x.astype(np.float64).copy())
    err = rel_error(analytic_grad, num)
    return err < tol, err
