
import java.util.ArrayList;

//Nolan Milligan 
//HW3
//COP3330

public class HW{
	//main function is left unchanged from docx template
	public static void main(String[] args) {

        String fullName = "Erika T. Jones";
		String employeeNumber = "ej789";
		double payRate = 100.0, hoursWorked = 1.0;

		Employee e;
		e = new Employee(fullName, employeeNumber, payRate, hoursWorked);

		Company company = new Company();
		
		company.hire (new Employee("Saeed Happy", "sh895" , 2 , 200));
		company.hire( new Employee("Enrico Torres" , "et897" , 3 , 150) );
		company.hire( new Employee("Nolan Milligan" , "nm235" , 4 , 150) );
		company.hire( new Employee("Yaddy Lopez" , "yl105" , 5 , 150) );
		company.hire (e);

		company.printCompanyInfo();
		company.printEmployees();

		
		
		//You may add as many employees to company as you want.
		//The TAs will add their own employees 
		//Make sure that each employee of company has a unique employeeNumber 
		
		company.printCheck("ab784");
		
		company.deleteEmployeesBySalary(256.36);
		
		company.reverseEmployees();
		
		System.out.println( company.SearchByName("WaLiD WiLLiAms") );

		company.printEmployees();
		
    }

    
    
}

class Employee {

	//employee objest will hold these four pieces of data to be accessed for each employee
	private String fullName, employeeNumber;
	private double payRate, hoursWorked;


	//this constructor method assigns the data passed in at object creation to the object's private variables
	Employee (String fullName, String employeeNumber, double payRate, double hoursWorked){
		this.fullName = fullName; this.employeeNumber = employeeNumber;
		this.payRate = payRate; this.hoursWorked = hoursWorked;
	}

	void printCheck(){
        double grossPay = hoursWorked * payRate;
		double Tax = grossPay * .06;
		System.out.println("\nEmployee's name:\t" + fullName);
		System.out.println("Employee's number:\t" + employeeNumber);
		System.out.println("Hourly Rate of Pay:\t" + payRate);
		System.out.println("Hours worked:\t\t" + hoursWorked);
		System.out.println("Total Gross Pay:\t" + grossPay);
		System.out.println("Deductions\n Tax(6%):\t\t" + Tax);
	}

    double netPay(){
        double grossPay = hoursWorked * payRate;
		double Tax = grossPay * .06;
        return grossPay - Tax;
    }

    @Override
    //when println(Employee_object) is called this will overide default output to this format instead
    public String toString() {
        return "[ " + employeeNumber + "/" + fullName + ", "
                + hoursWorked + " Hours @ " + payRate + " per hour ]";
    }

	// Getters
	public String getFullName() { return fullName; }
	public String getEmployeeNumber() { return employeeNumber; }
	public double getPayRate() { return payRate; }
	public double getHoursWorked() { return hoursWorked; }

	// Setters
	public void setFullName(String fullName) { this.fullName = fullName; }
	public void setEmployeeNumber(String employeeNumber) { this.employeeNumber = employeeNumber; }
	public void setPayRate(double payRate) { this.payRate = payRate; }
	public void setHoursWorked(double hoursWorked) { this.hoursWorked = hoursWorked; }
}

class Company {

	private ArrayList<Employee> employeeList;
	private static String companyName;
	private static String companyTaxId;

	public static String getCompanyName() { return companyName; }
	public static void setCompanyName(String companyName) { Company.companyName = companyName; }

	public static String getCompanyTaxId() { return companyTaxId; }
	public static void setCompanyTaxId(String companyTaxId) { Company.companyTaxId = companyTaxId; }
		
	public Company() {
		employeeList = new ArrayList<>();
		companyName = "People's Place";
		companyTaxId = "v1rtua7C0mpan1";
	}

	public boolean hire ( Employee employee ) {

		boolean is_new_employee = true;
		//check each employee that is currently in the employeeList to make sure this one has a unique empl num
		int arr_size = employeeList.size();

		for(int i=0; i<arr_size; i++){
			//if it is found that the employee's number is already in use method returns false
			if(employeeList.get(i).getEmployeeNumber() == employee.getEmployeeNumber()){
				is_new_employee = false;
				return is_new_employee;
			}
		}
		//if employee is unique they are added to the list and ture is returned
		employeeList.add(employee);
		return is_new_employee;
	}

	public static void printCompanyInfo() {
		System.out.println("Company Name:\t" + companyName);
		System.out.println("Company Tax ID:\t" + companyTaxId);
		//This method prints the compay name and its tax id 
		//You may choose to print that any way you like!
	}
	
	public void printEmployees() {
		//for each employee in the employee list print their to string 
		int arr_size = employeeList.size();
		for(int i=0; i<arr_size; i++){
			System.out.println(employeeList.get(i));
		}
	}
	public int countEmployees(double maxSalary){
		int arr_size = employeeList.size();
		int countEmployees = 0; 
		
		//for each employ if their net pay is less than the salary value
		//increment the employee count
		for(int i=0; i<arr_size; i++){
			if(employeeList.get(i).netPay() < maxSalary){
				countEmployees++;
			}
		}
		return countEmployees;
	}
	public boolean SearchByName(String fullName){
		int arr_size = employeeList.size();

		//if one of the employee's full names matches the one being searched
		//return true
		for(int i=0; i<arr_size; i++){
			if(employeeList.get(i).getFullName().equals(fullName)){
				return true;
			}
		}
		return false;
	} 
	public void reverseEmployees(){
		//new employee list to hold the values in reverse
		ArrayList<Employee> reverseList = new ArrayList<>();
		int arr_size = employeeList.size();

		//increment backwards through the original list
		//add values to the reverse list stating with the last value
		for(int i=(arr_size-1); i>=0; i--){
			reverseList.add(employeeList.get(i));
		}
		// now the original list is set to equal the reversList
		employeeList = reverseList;
	}

	public void deleteEmployeesBySalary(double targetSalary){
		int arr_size = employeeList.size();

		for(int i=(arr_size-1); i>=0; i--){
			if(employeeList.get(i).netPay() == targetSalary){
				employeeList.remove(i);
			}
		}
	}
	public void printCheck ( String employeeNumber) {
		int arr_size = employeeList.size();

		for(int i=(arr_size-1); i>=0; i--){
			if(employeeList.get(i).getEmployeeNumber().equals(employeeNumber)){
				employeeList.get(i).printCheck();
				return;
			}
		}
		System.out.println("NO SUCH EMPLOYEE EXISTS");
//This method prints the check of the employee whose employee number is //employeeNumber. It prints NO SUCH EMPLOYEE EXISTS if employeeNumber is //not a registered employee number.
	}
}

