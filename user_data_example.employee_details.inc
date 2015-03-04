<?php
/**
 * @file
 * Class include for Employee Detail getter and setter.
 */
 
class EmployeeDetails {
  /**
   * The associated user account.
   */
  protected $account;

  /**
   * The key for accessing data.
   */
  protected $dataKey = 'employee';

  /**
   * Constructor for Employee details data object.
   * @param $account
   * @throws \Exception
   */
  public function __construct($account) {
    if (!isset($account->data)) {
      throw new Exception("Malformed user added.");
    }
    $this->account = $account;
  }

  /**
   * Get the employee number for this user.
   *
   * @return int
   *   The employee number.
   */
  public function getEmployeeNumber() {
    $employee_number = $this->getDataValue('employee_number');

    return $employee_number;
  }

  /**
   * Set the employee number for this user.
   *
   * @param int $number
   *   The employee number.
   *
   * @throws InvalidArgumentException
   *   Thrown if the provided employee number is not an integer.
   */
  public function setEmployeeNumber($number) {
    if (!is_int($number)) {
      throw new InvalidArgumentException('Employee number provided is not an integer');
    }

    $this->setDataValue('employee_number', $number);
  }

  /**
   * Get the employee salary of this user.
   *
   * @return int
   *   The salary of the employee.
   */
  public function getEmployeeSalary() {
    $employee_salary = $this->getEmployeeDetail('salary');

    return $employee_salary;
  }

  /**
   * Set the employee salary of this user.
   *
   * @param int $salary
   *   The salary of the employee.
   *
   * @throws InvalidArgumentException
   *   Thrown if the provided employee salary is not an integer.
   */
  public function setEmployeeSalary($salary) {
    if (!is_int($salary)) {
      throw new InvalidArgumentException('Salary provided is not an integer');
    }

    $this->setEmployeeDetail('salary', $salary);
  }

  /**
   * Get the employee access level of this user.
   *
   * @return string
   *   The employee access level.
   */
  public function getEmployeeAccessLevel() {
    $employee_access_level = $this->getEmployeeDetail('access_level');

    return $employee_access_level;
  }

  /**
   * Set the employee access level of this user.
   *
   * @param string $access_level
   *   The access level: A, B or C.
   *
   * @throws InvalidArgumentException
   *   Thrown if the provided access level is not valid.
   */
  public function setEmployeeAccessLevel($access_level) {
    if (!in_array($access_level, array('A', 'B', 'C'))) {
      throw new InvalidArgumentException('Access level provided is not allowed');
    }

    $this->setEmployeeDetail('access_level', $access_level);
  }

  /**
   * Get the employee start date of this user.
   *
   * @return DateTime
   *   The timestamp corresponding to the employee start date.
   */
  public function getEmployeeStartDate() {
    $employee_start_date = $this->getEmployeeDetail('start_date');

    if (!empty($employee_start_date)) {
      $employee_start_date = new DateTime('@' . $employee_start_date);
    }

    return $employee_start_date;
  }

  /**
   * Set the employee start date of this user.
   *
   * @param DateTime $start_date
   *   The start date to set.
   *
   * @throws InvalidArgumentException
   *   Thrown if the start date is not a valid DateTime object.
   */
  public function setEmployeeStartDate(DateTime $start_date) {
    if (!is_a($start_date, 'Datetime')) {
      throw new InvalidArgumentException('Start date provided is not an instance of DateTime');
    }

    $this->setEmployeeDetail('start_date', $start_date->getTimestamp());
  }

  /**
   * Get a data value.
   *
   * @param string $key
   *   The key to get the value using.
   *
   * @return mixed
   *   The value retrieved.
   */
  protected function getDataValue($key) {
    $value = NULL;

    if (
      !empty($this->account->data[$this->dataKey]) &&
      !empty($this->account->data[$this->dataKey][$key])
    ){
      $value = $this->account->data[$this->dataKey][$key];
    }

    return $value;
  }

  /**
   * Set a data value.
   *
   * @param string $key
   *   The key to set the value using.
   * @param string $value
   *   The value to set.
   */
  protected function setDataValue($key, $value) {
    $this->account->data[$this->dataKey][$key] = $value;
  }

  /**
   * Get an employee data value.
   *
   * @param string $key
   *   The key to get the employee value using.
   *
   * @return mixed
   *   The value retrieved.
   */
  protected function getEmployeeDetail($key) {
    $value = NULL;

    $employee_details = $this->getDataValue('employee_details');
    if (!empty($employee_details[$key])) {
      $value = $employee_details[$key];
    }

    return $value;
  }

  /**
   * Set an employee data value.
   *
   * @param string $key
   *   The key to set the value using.
   * @param string $value
   *   The value to set.
   */
  protected function setEmployeeDetail($key, $value) {
    $this->account->data[$this->dataKey]['employee_details'][$key] = $value;
  }
}
