# Workshop 6: STL Containers

In this workshop, you store polymorphic objects in an STL container.

You are going to create an application that simulates a college management system.  This specific application, will focus on **Employee** and **Student**  and **Professor**.



## Learning Outcomes

Upon successful completion of this workshop, you will have demonstrated the abilities to:

- manage polymorphic objects using the vector container of the STL
- move a dynamically allocated object into a container
- code a range-based iteration on the objects in a container
- report and handle an exception



## Submission Policy

The workshop is divided into two coding parts and one non-coding part:

- *Part 1*: worth 0% of the workshop's total mark, is optional and designed to assist you in completing the second part.
- *Part 2*: worth 100% of the workshop's total mark, is due on **Sunday at 23:59:59** of the week of your scheduled lab.  Submissions of *Part 2* that do not contain the *reflection* are not considered valid submissions and are ignored.
- *reflection*: non-coding part, to be submitted together with *Part 2*. The reflection does not have marks associated to it, but can incur a **penalty of max 40% of the whole workshop's mark** if your professor deems it insufficient (you make your marks from the code, but you can lose some on the reflection).

The workshop should contain ***only work done by you this term*** or provided by your professor.  Work done in another term (by you or somebody else), or work done by somebody else and not **clearly identified/cited** is considered plagiarism, in violation of the Academic Integrity Policy.

Every file that you submit must contain (as a comment) at the top **your name**, **your Seneca email**, **Seneca Student ID** and the **date** when you completed the work.

- If the file contains only your work, or work provided to you by your professor, add the following message as a comment at the top of the file:

    > I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

- If the file contains work that is not yours (you found it online or somebody provided it to you), **write exactly which parts of the assignment are given to you as help, who gave it to you, or which source you received it from.**  By doing this you will only lose the mark for the parts you got help for, and the person helping you will be clear of any wrong doing.



## Compiling and Testing Your Program

All your code should be compiled using this command on `matrix`:

```bash
/usr/local/gcc/10.2.0/bin/g++ -Wall -std=c++17 -g -o ws file1.cpp file2.cpp ...
```

- `-Wall`: compiler will report all warnings
- `-std=c++17`: the code will be compiled using the C++17 standard
- `-g`: the executable file will contain debugging symbols, allowing *valgrind* to create better reports
- `-o ws`: the compiled application will be named `ws`

After compiling and testing your code, run your program as following to check for possible memory leaks (assuming your executable name is `ws`):

```bash
valgrind ws
```

To check the output, use a program that can compare text files.  Search online for such a program for your platform, or use *diff* available on `matrix`.




## Part 1 (0%)

The program should manage the activity at a college. See below the hierarchy of classes that should be created by the end of the workshop.

![Person Hierarchy](person_hierarchy.svg)

The first portion of this workshop consists of modules:
- `w6` (partially supplied)
- `Person` (supplied)
- `Employee`
- `College`
- `Utilities`

Enclose all your source code within the `sdds` namespace and include the necessary guards in each header file.





### `Employee` Module

This module defines a class that holds information about a single Employee.


***Private Data***

Design and code a class named `Employee`, that inherits the abstract class `Person` (supplied), and that should be able to store the following information (for each attribute, you can choose any type you think it's appropriate--you must be able to justify the decisions you have made):

- **m_name**
- **m_age**
- **m_id**


***Public Members***

- a custom constructor that receives an object of type `std::istream&` as parameter. This constructor should be able to read a single record from the stream, extract all the information about a single Employee and store it in the attributes. Each record has the following format:
  ```
  TAG,NAME,AGE,EMPLOYEE ID
  ```
  - `TAG`, is a single character representing the type of person: `e` or `E` for Employee. Any other tag is considered invalid.  The tag is handled in `Utilities`.
  - `NAME`, the name of the employee
  - `AGE`, an integer containing the official age of the employee. If the content of this field is not a number, then the field is considered invalid and should throw a message made up of the name of the employee and "++Invalid record!"
  - `EMPLOYEE ID`, represents the Employee ID at the College. It should start with letter `E` Any other character is considered invalid should throw a message made up of the name of the employee and "++Invalid record!".
  - any space at the beginning/end of each field should be removed.
- `std::string status() const`: a query that returns the string `Employee`
- `std::string name() const`: a query that returns the name of the employee
- `std::string id() const`: a query that returns the id of the employee
- `std::string age() const`: a query that returns the age of the employee
- `void display(std::ostream& out) const`: a query that inserts in the first parameter the content of the employee object in the format `| "EMPLOYEE" | id | name | age |`, where
  - left justified
  - the word `Employee`, field of size 10
  - `id`, field of size 10
  - `name`, field of size 20
  - `age`, field of size 3
  - see alignment in the sample output.

**Add any other private member that is required by your design!**



### `College` module

This module defines a class that holds information about college management system.


***Private Data***

Design and code a class named `College` that should be able to store the following information:

- `std::vector<Person*> m_persons`: a vector that store all the persons present at this college.  All these `Person` objects will be dynamically allocated; this class should manage them.


***Public Members***
- The `College` should have the copy operations disabled
- `College& operator +=(Person* thePerson)`: adds the address of the person object received as parameter into the `m_persons` vector.
- `void display(std::ostream& out) const`: iterates over the persons stored in `m_persons` and prints their details  using the following format (one person per line, see the sample output for formatting details).
  ```
  -----------------------------------------
   Test #1 Persons in the college!        |
  -----------------------------------------
  Person
  Person
  ...
  -----------------------------------------
  ```

  ```
  -----------------------------------------
   Test #2 Persons in the college!        |
  -----------------------------------------
  Person
  Person
  ...
  -----------------------------------------
  ```
  Use `Person::display()` for the first test, and use the other public functions for the second test.
  **To iterate over the elements of the vector, use STL iterators!**



### `Utilities` module

This module should contain a single function that creates instances on the `Person` hierarchy:
```cpp
Person* buildInstance(std::istream& in);
```

This function should extract data from the parameter; if the first non-blank character is `e` or `E`, then this function should **dynamically** create an instance of type `Employee` passing the stream to the constructor, and return it to the client.

If the first non-blank character is anything else (or there are no more characters to extract), this function should return `nullptr`.

Because the input file contains two types of delimiters (`\n` for records, and `,` for the fields in a record), you can use the class `std::stringstream` (utilization of this class is not mandatory, the extraction can be achieved without using it).

When implementing the `buildInstance` function, consider the following STL class:
  - [std::stringstream](https://en.cppreference.com/w/cpp/io/basic_stringstream/basic_stringstream)



### `w6` Module (supplied)


The tester module for this portion has been partially supplied. Modify it only in places marked with `ToDo` to add the missing code.

When doing the workshop, you are encouraged to write your own tests, focusing on a single implemented feature at the time, until you get all functionality in place.



### Sample Output

When the program is started with the command (the file `college_clean.txt` is provided):
```bash
ws college_clean.txt
```
the output should look like the one from the `sample_output.txt` file.





### Test Your Code

To test the execution of your program, use the same data as shown in the output example above.

Upload your source code to your `matrix` account. Compile and run your code using the latest version of the `g++` compiler (available at `/usr/local/gcc/10.2.0/bin/g++`) and make sure that everything works properly.

Then, run the following command from your account (replace `profname.proflastname` with your professor’s Seneca userid):
```bash
~profname.proflastname/submit 345_w6_p1
```
and follow the instructions.

***This part represents a milestone in completing the workshop and is not marked!***










## Part 2 (100%)

The second part of this workshop upgrades your solution to include two more module and update some existing modules:
- `Student`
- `Professor`
- `Utilities` (to be updated)
- `College` (to be updated)
- `w6` (partially supplied)





### `Professor` Module


Add a `Professor` module to your project. A `Professor` is an `Employee` (this class should inherit `Employee`).

***Private Data***

- `m_department`: the department the professor works at 


***Public Members***

- `Professor(std::istream& in)`: calls the constructor from `Employee` to build the sub-object, and then it extracts the last field from the stream containing the department. The input format for a professor is `TAG,NAME,AGE, EMPLOYEE ID,DEPARTMENT`.  `TAG`, is a single character representing the type of person: `p` or `P` for professor Any other tag is invalid. The tag is handled in Utilities.
- `void display(std::ostream& out) const`: calls `Employee::display()` to print the information about the Employee, and adds `department|"Professor"` at the end. The format should be `| "EMPLOYEE" | id | name | age |department|"Professor"`
- `std::string status() const`: a query that returns word `Professor`
- `std::string department() const`: a query that returns the department

This class should not have access to the attributes of the parent class.



### `Student` Module

This module defines a class that holds information about a single Student.


***Private Data***

Design and code a class named `Student`, that inherits the abstract class `Person` (supplied), and that should be able to store the following information (for each attribute, you can choose any type you think it's appropriate--you must be able to justify the decisions you have made):

- **m_name**
- **m_age**
- **m_id**
- **m_courses**: a dynamically allocated array of strings
- **m_count**: the number of courses in the array


***Public Members***
- a custom constructor that receives an object of type `std::istream&` as parameter. This constructor should be able to read a single record from the stream, extract all the information about a single student and store it in the attributes. Each record has the following format:
  ```
  TAG,NAME,AGE,STUDENT ID,NUMBER_OF_COURSES,LIST_OF_COURSES
  ```
  - `TAG`, is a single character representing the type of person: `s` or `S` for student. Any other tag is considered invalid. The tag is handled in Utilities.
  - `NAME`, the name of the student
  - `AGE`, an integer containing the official age of the student. If the content of this field is not a number, then the field is considered invalid and should throw a message made up of the name of the student and "++Invalid record!"
  - `STUDENT ID`, represents the Student ID at the college. It should start with letter `S`. Any other character is considered invalid should throw a message made up of the name of the student and "++Invalid record!".
  - `NUMBER_OF_COURSES`, an integer containing the number of courses this student has completed. If the content of this field is not a number, then the field is considered invalid and should throw a message made up of the name of the student and "++Invalid record!"
   - `COURSES`, lists names of the courses this student has completed.  These courses are separated by `,` delimiter.  The number of courses is equal to the integer `NUMBER_OF_COURSES`
  - any space at the beginning/end of each field should be removed.
- `std::string status() const`: a query that returns the word `Student`
- `std::string name() const`a query that returns the name of the Student
- `void display(std::ostream& out) const`, a query that inserts in the first parameter the content of the employee object in the format `| Student | id | name | age | courses`, where
  - `Student`, field of size 10
  - `id`, field of size 10
  - `name`, field of size 20
  - `age`, field of size 3
  - `courses`, list of courses this student has completed separated by `,` delimiter
  - see alignment in the sample output.
- this class should manage the `m_courses` resource; disable the copy operations.

**Add any other private member that is required by your design!**




### `Utilities` module

Update the `buildInstance` to also build an instance of type `Student` if the first non-blank character extracted from the stream is `s` or `S`, and to build an instance of type `Professor` if the first non-blank character extracted from the stream is `p` or `P`

If there is no more information to be extracted from the stream, this function should return `nullptr`.





### `College` Module


Update this module to include two additional public functions.

***Public Members***

- a destructor. This function should iterate over the objects stored in the vector, and delete each one of them (note that the first portion has a memory leak because the dynamically allocated persons were not deleted anywhere).

- `void select(const T& test, std::list<const Person*>& persons)`: a **template** function that iterates over the persons stored in the `m_persons`, and adds to the second parameter all persons for which the `test` is true. The first parameter (`test`) can be a lambda expression, a pointer to a function, or a functor that matches the prototype:
  ```cpp
  bool func(const sdds::Person*);
  ```

  **Since this is a template function, it must be implemented in the header!** The class is not a template.






### `w6` Module (partially supplied)


This module has some missing parts. The missing parts are marked with `TODO`, describing what code you should add and where. **Do not modify the existing code, only add what is missing!**



### Sample Output

When the program is started with the command (the files are provided):
```bash
ws college.txt
```
the output should look like the one from the `sample_output.txt` file.




### Reflection

Study your final solution, reread the related parts of the course notes, and make sure that you have understood the concepts covered by this workshop. **This should take no less than 30 minutes of your time and the result is suggested to be at least 150 words in length.**

Create a **text** file named `reflect.txt` that contains your detailed description of the topics that you have learned in completing this particular workshop and mention any issues that caused you difficulty and how you solved them. Include in your explanation—**but do not limit it to**—the following points:
- Why do you need to deallocate the dynamically allocated memory in your vector?
- When building an object from the input file, different things can go wrong: the record represents an unknown type of person, or record contains invalid data. How can the function `loadData()` detect what went wrong? Can you think at another solution than the one you have implemented?
- In this workshop you had to use `std::list<sdds::Person*>` and `std::vector<sdds::Person*>` to store a collection of persons as pointers. Could you have used `std::list<sdds::Person>` and `std::vector<sdds::Person>` instead? **Justify your answer!**

To avoid deductions, refer to code in your solution as examples to support your explanations.





### Submission

To test and demonstrate execution of your program use the same data as shown in the output example above.

Upload the source code and the reflection file to your `matrix` account. Compile and run your code using the latest version of the `g++` compiler (available at `/usr/local/gcc/10.2.0/bin/g++`) and make sure that everything works properly.

Then, run the following command from your account (replace `profname.proflastname` with your professor’s Seneca userid):
```bash
~profname.proflastname/submit 345_w6_p2F
```
and follow the instructions.

**:warning:Important:** Please note that a successful submission does not guarantee full credit for this workshop. If the professor is not satisfied with your implementation, your professor may ask you to resubmit. Resubmissions will attract a penalty.






### Submission

To test and demonstrate execution of your program use the same data as shown in the output example above.

Upload the source code and the reflection file to your `matrix` account. Compile and run your code using the latest version of the `g++` compiler (available at `/usr/local/gcc/10.2.0/bin/g++`) and make sure that everything works properly.

Then, run the following command from your account (replace `profname.proflastname` with your professor’s Seneca userid):
```bash
~profname.proflastname/submit 345_w6_p2
```
and follow the instructions.

**:warning:Important:** Please note that a successful submission does not guarantee full credit for this workshop. If the professor is not satisfied with your implementation, your professor may ask you to resubmit. Resubmissions will attract a penalty.
