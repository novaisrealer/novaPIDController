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

  frc::XboxController m_xbox{0};
  rev::CANSparkMax samSmithLeft1{1, rev::CANSparkMaxLowLevel::MotorType::kBrushless};
  rev::CANSparkMax samSmithLeft2{2, rev::CANSparkMaxLowLevel::MotorType::kBrushless};
  rev::CANSparkMax samSmithRight1{3, rev::CANSparkMaxLowLevel::MotorType::kBrushless};
  rev::CANSparkMax samSmithRight2{4, rev::CANSparkMaxLowLevel::MotorType::kBrushless};

  rev::SparkMaxPIDController samSmithPIDLeft{samSmithLeft1.GetPIDController()};


};
