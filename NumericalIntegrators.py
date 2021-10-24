def eval_derivs(X):
    # Constants
    m = 1
    k = 1

    # New state derivative vector [xdot and xdoubledot]
    xdd = -(k/m) * X[0]
    Xdot = np.array([X[1], xdd])
    return Xdot
def rk4(dt, X, evaluate):
    # Calculate Terms
    k1 = dt * evaluate(X)
    k2 = dt * evaluate(X + 0.5*k1)
    k3 = dt * evaluate(X + 0.5*k2)
    k4 = dt * evaluate(X + k3)

    # Update X
    X_new = X + (1/6.)*(k1 + 2*k2 + 2*k3 + k4)
    return X_new

def euler(dt, X, evaluate):

    # Calculate Terms
    k1 = dt * evaluate(X)

    # Update X
    X_new = X + k1
    return X_new

# Initial conditions
X = np.array([1,0])
# Time step
dt = 0.25
# End time
t = 10
iters = int(t/dt)

# Data structure for results
D = np.zeros((iters+1, 2))
D[0] = X
T = np.linspace(0,t, iters+1)

# Iterate over number of steps
for i in range(iters):
    # Compute an integration step and save
    D[i+1] = euler(dt, D[i], eval_derivs)
