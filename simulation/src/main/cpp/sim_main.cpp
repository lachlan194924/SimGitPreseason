#include "sim_main.h"
#include "motor_window.h"
#include "xbox_window.h"

#include "mockdata/PWMData.h"
#include "hal/HAL.h"

#include <iostream>
#include <array>

static std::vector<sim_motor_window> _motors;

void sim_main::run() {
  std::cout << "Simulation Started" << std::endl;
  HAL_Initialize(500, 0);

  _motors.reserve(10);
  for (int i = 0; i < 10; i++)
    _motors.emplace_back(i);

  (new sim_xbox_window())->start();
  std::cout << "Simulation Initialized!" << std::endl;
}