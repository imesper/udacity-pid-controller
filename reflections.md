# PID Controller

This project consist in programming a PID controller to control the steering angle of a car.

## PID Controller

The PID Controller is a very well know linear controller that follows the equation:

![alt text](PIDController_Equation.png "Logo Title Text 1")

The control input is the summation of three terms, the proportional, the integral, and the derivative.

### Error

For a PID controller the error e is the desired value, also called reference, minus the actual value, as shown below:
```
   *e = Vd - v;*
```
Where *Vd* is the desired value and *v* is the actual value.
 
### PID Gains - Hyperparameters

#### Proportional

The proportional term is the multiplication of the proportional gain Kp and the error e.
As cleared stated by the name, it makes the input proportional to the error, i.e., larger error larger input.
``` 
   *u(t) = kp ⋅ e*  
```

#### Integral

The integral term is the multiplication of the integral gain Ki and the integration of the error e, ∫E.
The term in practice is the acumulation of the errors over time, so small errors can be corrected.

``` 
   *u(t) = ki ⋅ ∫e*  
```

#### Derivative

The derivative term is the multiplication of the derivative gain Kd and the derivative of the error e over time, de/dt.
The derivative  makes a kind of prediction of the future state of the error, as it observers the rate of change on the error, thus 
preventing overreacting to an error, i.e., overshooting.

``` 
   *u(t) = kp ⋅ de/dt*  
```

### Choosing PID Gains - Hyperparameters

In the project the PID gains were chosen by emperical method. Setting the propotional gain first,
we have a general idea on what to do next. In this case, the next important gain was derivative, as it
prevent overshooting of the controller. Then, the integral gain was choose to correct small and slow 
errors that cause the car to deviate from the desired position.
 
## Authors

* **Ian Esper**