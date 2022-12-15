// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <string>
#include <rev/CANSparkMax.h>
#include <rev/SparkMaxPIDController.h>
#include <frc/XboxController.h>


#include <frc/TimedRobot.h>
#include <frc/smartdashboard/SendableChooser.h>

class Robot : public frc::TimedRobot {
 public:
  void RobotInit() override;
  void RobotPeriodic() override;
  void AutonomousInit() override;
  void AutonomousPeriodic() override;
  void TeleopInit() override;
  void TeleopPeriodic() override;
  void DisabledInit() override;
  void DisabledPeriodic() override;
  void TestInit() override;
  void TestPeriodic() override;

 private:
  frc::SendableChooser<std::string> m_chooser;
  const std::string kAutoNameDefault = "Default";
  const std::string kAutoNameCustom = "My Auto";
  std::string m_autoSelected;
  // Controller defined as m_xbox
  frc::XboxController m_xbox{0};
  // Motors defined. 2 on the left and 2 on the right
  rev::CANSparkMax mLeft1{1, rev::CANSparkMaxLowLevel::MotorType::kBrushless};
  rev::CANSparkMax mLeft2{2, rev::CANSparkMaxLowLevel::MotorType::kBrushless};
  rev::CANSparkMax mRight1{3, rev::CANSparkMaxLowLevel::MotorType::kBrushless};
  rev::CANSparkMax mRight2{4, rev::CANSparkMaxLowLevel::MotorType::kBrushless};
  // PID controllers defined for all four motors
  rev::SparkMaxPIDController PIDLeft1{mLeft1.GetPIDController()};
  rev::SparkMaxPIDController PIDLeft2{mLeft2.GetPIDController()};
  rev::SparkMaxPIDController PIDRight1{mRight1.GetPIDController()};
  rev::SparkMaxPIDController PIDRight2{mRight2.GetPIDController()};
  
};
