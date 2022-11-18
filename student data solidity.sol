//Step 1: Open Remix IDE.

//Step 2: Click on File Explorers and select Solidity in the environment and create a new file StudentMarksMangmtSys.sol by clicking on New File section.

//Step 3: Build a smart contract that contains all the details of the student with the help of Remix IDE by clicking on the file name.

// Solidity program to implement
// the above approach
pragma solidity >= 0.7.0<0.8.0;

// Build the Contract
contract MarksManagmtSys
{
	// Create a structure for
	// student details
	struct Student
	{
		int ID;
		string fName;
		string lName;
		int marks;
	}

	address owner;
	int public stdCount = 0;
	mapping(int => Student) public stdRecords;

	modifier onlyOwner
	{
		require(owner == msg.sender);
		_;
	}
	constructor()
	{
		owner=msg.sender;
	}

	// Create a function to add
	// the new records
	function addNewRecords(int _ID,
						string memory _fName,
						string memory _lName,
						int _marks) public onlyOwner
	{
		// Increase the count by 1
		stdCount = stdCount + 1;

		// Fetch the student details
		// with the help of stdCount
		stdRecords[stdCount] = Student(_ID, _fName,
									_lName, _marks);
	}

	// Create a function to add bonus marks
	function bonusMarks(int _bonus) public onlyOwner
	{
		stdRecords[stdCount].marks =
					stdRecords[stdCount].marks + _bonus;
	}
}

//Step 4: After building the contract compile it. Select the compiler version before clicking on Compile button. 

//Compile the contract

//Step 5: After successful compilation, to deploy the contract, select the Environment JavaScript VM (Berlin) before clicking on the Deploy button.

//Deploy the contract

//Step 6: If the contract is successfully deployed then deployed contract is obtained. Open the deployed contract and add the student details and transact it.

//Deployed contract

//Step 7: Add the bonus marks if you want to give them to the student and transact it after that click on the stdCount. One can see the student details after calling the stdRecords by entering the stdCount.
