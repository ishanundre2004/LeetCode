select eu.unique_id, e.name from Employees as e
left join EmployeeUNI as eu
on eu.id = e.id;