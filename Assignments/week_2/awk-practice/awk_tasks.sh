#!/bin/bash

FILE="employees.txt"

echo "Task 1: Names and Departments"
awk -F',' '{print $1, $2}' $FILE


echo ""
echo "Task 2: Engineering Employees"
awk -F',' '$2=="Engineering" {print}' $FILE


echo ""
echo "Task 3: Gross Pay Calculation"
awk -F',' '{
    pay=$3*$4
    printf "%s gross pay: $%d\n", $1, pay
}' $FILE


echo ""
echo "Task 4: Line Number and Field Count"
awk -F',' '{
    printf "%d (%d fields): %s\n", NR, NF, $0
}' $FILE


echo ""
echo "Task 5: Total Engineering Payroll"

awk -F',' '
BEGIN {
    total=0
}

$2=="Engineering" {
    total += $3*$4
}

END {
    printf "Total Engineering Payroll: $%d\n", total
}
' $FILE
