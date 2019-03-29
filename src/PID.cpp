#include "PID.h"
#include <iostream>
/**
 * TODO: Complete the PID class. You may add any additional desired functions.
 */

using namespace std;

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp_, double Ki_, double Kd_) {
    this->d_prev_error = 0;
    this->i_error = 0;
    this->Kp = Kp_;
    this->Ki = Ki_;
    this->Kd = Kd_;
}

void PID::UpdateError(double cte) {

    const double threshold = 10;
    this->d_error = cte - this->d_prev_error;
    this->d_prev_error = cte;

    this->p_error = cte;

    this->i_error += cte;

    if(this->i_error > threshold) {
        this->i_error = threshold;
    } else if (this->i_error < -threshold){
       this->i_error = -threshold;
    }

    cout << d_error << " " << p_error << " " << i_error << endl;
}

void PID::SpeedUpdateError(double speed_error) {

    const double threshold = 10;
    this->d_error = speed_error - this->d_prev_error;
    this->d_prev_error = speed_error;
    this->p_error = speed_error;

    if(this->i_error > threshold) {
        this->i_error = threshold;
    } else if (this->i_error < -threshold){
       this->i_error = -threshold;
    } else {
      this->i_error += speed_error;
    }

    cout << d_error << " " << p_error << " " << i_error << endl;
}


double PID::TotalError() {

  return -this->p_error * this->Kp - this->d_error * this->Kd - this->i_error * this->Ki;
}
