# **Group 67**
Group 67
1. Yam Chak Fung Wesley
2. Chu Wai Kit
## **Part 1: Overview**
In this part, problem statement and problem setting is shown. 
### **1. Problem statement**
   People nowadays often fail to plan on their own financial status. It indeed undermines many aftermaths in various aspects, say interpersonal relationship within family and qualiy of life. It is pravalent to see people are broke due to some reasons in newspaper, like uncontrolled leisure expenditure. 
 
  Undenibly, managing financial status is an essential skill for all of us. Recently many researches have shown the benefit of managing and planing since early stage. In light of this, we would like to develop an accounting system to help parents to inculcate their kids the concept of currency as well as helping teens to develop an useful habit.
  
  To achieve this, we have four main features to facilitate the use of the systems. They are basic financial managment, prediction/report, login function, task trigger. These will be discussed in the following section. 
 
  In short, this system provides a spectrum of user-friendly, safe and efficient features to view, manage and track their kids' financial status. Thus, student can learn to plan better. As a result , we can promote a good econ-planning mindset to our next generation in a long term, contributing to the society. 
 
### **2. Problem setting**
???
  
## **Part 2: Functionalities and features**
  In this part, four main features - basic financial managment, prediction/report, login function, task trigger - will be discussed in detail one by one. 
### **1. Basic Financial Managment**

### **2. Prediction/Report**

### **3. Login Function**
As we mentioned, financial status is sensitive personal information. A secured login system to prevent unwanted users to access is essential. There are 4 options here. They are Login, Register, Forget and Exit repectively.  
#### Login
User first input username. If the username does not exist, a alert will pop out and user have to input again. And then user input the password. There are only 5 chances input the right password considering the bot attack. After 5 times, the program will be terminated.  Once the user input the username and corresponding password correctly, it shows "Welcome" and enters the main menu.

#### Register
New user can sign up for an account before they use the program. Since the financial xxx is for the public. User can first input the username. If there is repetitive username, again an alert pops out. Then the user will need to input the password. For security reason and avoid unreasonally many data, the password must be within 6-20 characters combining both characters and numbers. Moreover, we have double validation to ensure users input the right password. If registeration is success, a notification shows up as well. 

#### Forget
Considering users may forget their username and password, they can input their email address here to find their data by entering their email address. To avoid the invalid data, there is a format check. Any invalid email leads to an alert. 

#### Exit
After you use the system, you can leave here :)

### **4. Task Trigger**
Since the purpose of this system is to let kids have a user-friendly, safe and efficient tool to manage financial status by themselves, parents also plays an important role. This function aims to have interactivity between parents and their children, allowing parents to provide some solid motivation to their kids. 
We use linked list to achieve this purpose for 2 reasons - the system can by better management on dynamic data structure as well as insertion and deletion. We have 5 features here. 
#### Assign Task
Parents can assign the task here. There is a node for each task with 4 data. The first one stores the task name, then the amount of bonus for completing the task, the third one is to check if the task has been done or not. 
First they need to input the task. It is okay even it is a sentence like "Do Homework". Then they can input the bonus. The system will ask you for double confirmation and then continuation. User can simply type 'y' or 'n' to decide so it is more userfriendly. 
#### View Task
Parents can check if tasks have finished or not here. Task name, bonus and status are all shown here. Moreover, if they wish to delete unwanted the task, they can simply input the line of the task. The menu will change instantly. The corresponding data in the memory will also be deleted at the same time to avoid data leak. 

#### Initialize Task
This feature provides a quick way to clear all the tasks. Again, a double comfimation is required to prevent wrong input. 

#### Complete Task
Kids can view the task here. Task name, bonus and status are all shown here. Moreover, if they have finished the task, they can simply input the line of the task. The menu will change instantly and the income will be recorded. 

## **Part 3: How can I get started**
The first step is to register and login. If you forget your username or password, do not worry, you can input your email and we will contact you. 

After signing in, there are Children mode and Parents mode. 
## **Part 4: Limitations**
