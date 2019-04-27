# **Group 67**
Group 67
1. Yam Chak Fung Wesley
2. Chu Wai Kit
## **Part 1: Overview**
This part focuses on problem statement and problem setting. 
### **1. Problem statement**
   People nowadays often fail to plan on their own financial status. It creates many aftermaths in various aspects, say interpersonal relationship and qualiy of life. Todate, it is commmon to see brankruptcy due to some reasons, like overconsumption on leisurement.
 
  Undenibly, managing financial status is an essential skill for all of us. Recently many researches have shown the benefit of managing and planning since early stage. In light of this, we would like to develop an accounting system to help parents to inculcate their kids the concept of currency as well as helping teens to develop an useful habit.
  
  To achieve this, we have four main features to facilitate the use of the systems. They are basic financial managment, prediction/report, login function, task trigger. These will be discussed in the following sections. 
 
  In short, this system provides a spectrum of user-friendly, safe and efficient features to view, manage and track their kids' financial status. Thus, student can learn to plan better. As a result , we can promote a good econ-planning mindset to our next generation in a long term, contributing to the society. 
 
### **2. Problem setting**
1. How to make a user friendly environment for add/delete/edit for different day?
2. How to create a quick search and sort for our customers?
3. How to give our customers detailed report and prediction for their future?
4. How to make interation between parents and children?
5. If a family has 3 childrens, how can we make a report to them seperately?
## **Part 2: Functionalities and features**
  In this part, four main features - basic financial managment, prediction/report, login function, task trigger - will be discussed in detail one by one. 
### **1. Basic Financial Managment**
   #### 1.1 Edit the menu
   Foremost, we allow kids to input, delete and edit their datas.
   They need to go section *1* and enter the the date to do edition.
   They can choose the options freely.
   They will be quited if the data doesn't exist.
      ##### Important- what is date doesn't exist
      They need to go back the menu and go to **initialization** to create the date
      ##### Insert
      There are 7 options and they can input their values repectively.
      They need to enter number of items that they need to input.
      Then enter the items' name, number of items, price of that.
      If the number of items is bigger than 10 or price is lager than 100, double validation is needed.
      ##### Remove
      They can choose the line they don't want after entering a valid date.
      They can enter many "error line" and pressed 0 as to leave.
      We will then count the removed price and re-calculate the sum of that scope. A new sum will be shown in the   username_date_scope.txt file.
   ##### Edit
  They can choose the line that they want to modify after entering a valid date.
  They need to re-enter the data and we will calculate the sum again and write to to username_date_scope.txt
  In a nutshell, our manupilation of data is very user-friendly. Also, there is a short report for each date and each scope counting the number of items, price and name. To obtain with such an option, the only annoying way is to initialize the data but in-return, we will give you the best document.
  #### 1.2 - search
  We allow user to search their files by entering their dates. Then, they can choose to read speific file or all files. That can provide flexibilty and quite accessibilty to what you did in which day and which scope respectively.
  
  #### 1.3 - sort
  We allow user to sort their data in each scope and day. There are acesending and descending order in "alphabetical orders of name, numerical orders of price and number of items". Therefore, it provides a good search view for user to find their datas instantly. It is super user-friendly.
  
  #### 1.4 - setTasks
   Kids need to choose which tasks they've done and the pocket moeny will instantly store to the username_date_gain.txt. Then, they can ask their parents to gain their money after they finish the task.
      
  #### 1.5 - Deep Learning
   Here, users need to input the 2 dates, which is a duration. Then, our system will train the file within that period to optimize the best paramters for prediction. We allow the user to choose their only learning rate, of course, we have given the suggestion on learning rate. Then, the accuracy and prediction of the next dates will be given.
   User should frequently use this area to help training the data :) . The more they train, the more accurate the model is. So, in this way, we encouage them to use our apps frequently.
   Here, we use backward-propagation. The layers are as following, which are typical.
   Affine1(fully connected)->ReLu->Affine2(fully connected)->softmax->entrophy loss
   Then do it backwardly.
   Our default learning rate is 0.05 which can correctly predict the price within $100 per day.
   If the user can input all the scopes per day, the accuarcy can be enhanced.
   It is used for the long term-prediction
#### 1.6 Report
   We will generate a daily report of specific date. The customers can also read their previous report in file. The function will be dicussed below.
##### Skilled fulfilled
   ● Dynamic memory management(vector,link-list,array,class,struct)
   ● File input/output(file in and out of the data)
   ● Data manipulation such as sorting, searching, adding/editing/deleting data records(merge sort, selection sort, adding appending,delete edit)
   ● Program codes in multiple files (25 cpp and h file)
   ● Proper indentation and naming styles
   ● In-code documentation
#### **2. Prediction/Report**
   The report contains the percentage and the total sum of each scope. The precentage can tell the kids about their financial status statistically. Then, we have mean prediction and deep learning prediction which will provide 2 kinds of prediction to kids. Hence, they can plan for next day easily.
      
### **3. Login Function**
As we mentioned, financial status is sensitive personal information. A secured login system to prevent unwanted users to access is essential. There are 4 options here. They are Login, Register, Forget and Exit repectively. The feasures is discussed one by one in the following  
#### 3.1 Multi-users
With the login system, we do support **multi-users**. Say a family of 3 childrens, they can share the same computer but their documents will be separated. 
#### 3.2 Login
User first input username. If the username does not exist, a alert will pop out and user have to input again. And then user input the password. There are only **5 chances** input the right password considering the bot attack. After 5 times, the program will be terminated.  Once the user input the username and corresponding password correctly, it shows "Welcome" and enters the main menu. 

#### 3.3 Register
New user can sign up for an account before they use the program. Since the financial status is for the public. User can first input the username. If there is repetitive username, again an alert pops out. Then the user will need to input the password. For security reason and avoid unreasonally many data, the password must be within **6-20 characters combining both characters and numbers**. Moreover, we have double validation to ensure users input the right password. If registeration is success, a notification shows up as well. 

#### 3.4 Forget
Considering users may forget their username and password, they can input their email address here to find their data by entering their email address. To avoid the invalid data, there is a **format check**. Any invalid email leads to an alert. 

#### 3.5 Exit
After you use the system, you can leave here :)

### **4. Task Trigger**
Since the purpose of this system is to let kids have a user-friendly, safe and efficient tool to manage financial status by themselves, parents also plays an important role. This function aims to have interactivity between parents and their children, allowing parents to provide some solid motivation to their kids. 
We use **linked list** to achieve this purpose for 2 reasons - the system can by better management on dynamic data structure as well as insertion and deletion. We have 5 features here. 
#### 4.1 Assign Task
Parents can assign the task here. There is a node for each task with 4 data. The first one stores the task name, then the amount of bonus for completing the task, the third one is to check if the task has been done or not. 
First they need to input the task. It is **okay even it is a sentence** like "Do Homework". Then they can input the bonus. The system will ask you for double confirmation and then continuation. User can simply type 'y' or 'n' to decide so it is more user-friendly. 
#### 4.2 View Task
Parents can check if tasks have finished or not here. Task name, bonus and status are all shown here. Moreover, if they wish to delete unwanted the task, they can simply input the line of the task. The **menu will be updated instantly**. The corresponding data in the memory will also be deleted at the same time to avoid data leak. 

#### 4.3 Initialize Task
This feature provides a **quick way to clear all the tasks**. Again, a double comfimation is required to prevent wrong input. 

#### 1.5 Sort Task
Only sorting by price is provide since it is not a easy way to sort a linked list. However, A special algorithom is used to sort the linked list - **Merge Sort**. It is preferred for sorting linked list. It is because in linked list to access i th index, the system travels every node from the head to look for i th node as we don’t have continuous block of memory. Merge sort accesses data sequentially and the need of random access is low, thus **higher efficiency**. 

#### 1.4 Complete Task
Kids can view the task here. Task name, bonus and status are all shown here. Moreover, if they have finished the task, they can simply input the line of the task. The **menu is updated at once** and **the income will be recorded at the same time**. 

## **Part 3: How can I get started**
We can start by login.cpp and excute the file. 
The first step is to register and login. If you forget your username or password, do not worry, you can input your email and we will contact you. 

After signing in, there are 2 modes - Children mode and Parents mode by entering 1 or 2. 

#### If you are parents
It is the mode for parents to modify the task. Parents can assign tasks, delete tasks and sort tasks here. There are four options here. 
First they enter 1 to assign tasks. First they need to enter the task name, then the bonus once the kid finished that task. They system will ask for the confirmation again to ensure no mistakes. If parents wish to continue, they can just enter 'y'. Or enter 'n' to return to the menu. 
Then, they can remove tasks assigned in by entering 2. The menu will show the current tasks in real time. If you remove any one of it, the menu responses at the same time. 
Sort tasks is to sort by price only if parents wish kids to finish some more urgent or valuable tasks first. 
Once everything is done, users can just press'0' to leave and they can comeback to modify anytime. 

#### If you are kids 
**Must Read**
For children mode, there are 7 options. The most important thing is that you need to **initialize(option 6), so that you can create a file of that day for futher usage**. For remaining options are easy to follow. Yet, second point to notice is that, for deep learning part, you just **need to initialize it once in deep learning menu or report menu for the first time**. It will ask you if initialize. You just need to choose Yes **for the first time**, then enter No for later.(very important, i recap it twice)

**MMDD**
We want you to give us month and day of specific date. For example 3rd March is 0303; 20th June is 0620; 12th Dec is 1212. 
**Report**
The report consist of two parts - the current date's report and the prediction. First you need to input the date and category you wish to check. 
The screen will show the report and a text file is generated for users. 
**Initialization on main menu**
Create a new file for specific date

**Re-Initialization on add/delete/edit menu**
To clear all data on specific date
**Sort** 
You can Sort here. 
**Edit**
Kid can insert, delete and edit their expense and income here. 
You need to enter the date in form of MMDD (eg. 1st of July -> 0701) first to delcare the specific date you wish to modify. Then you can choose Insert, remove or edit. After it, you need to choose the category, then choose the number of different items to input, then the name of the item, number of the item, total price and confirm it. Remind that the total price means total sum of that price. 

**Task trigger** 
In the main menu, there will be a reminder remind you how many task you have to do. For example, if your parents assign 2 tasks, then it will shown '2 tasks is waiting you'. You can view tasks here and if you have finish, select the line of that task. It will change from 'Doing' to 'Done' instantly. 
## **Part 4: Limitations**
1. Checkers have been added to avoid invaid input, say in the main menu, if users input any characters except 0- 7, an alert pops out. So we try to simplify the input by just entering a character or number. However, it is still impossible to include every exception case.  
2. Only standary library is allowed and being year 1 students, a lot of features do not work as we expected, like we made masking for the password and deep learning model for prediction, providing higher security and flexibility. Still, it is a precious opportunity for learning. 

3. Too few data. As deep learning model requires lot of data and time to train. Thus, the predicition is not accurate for now. However,  we do not have a database to collect and save that amounts of data methodically. It is still at a primary stage and we will enhence it in the future. 

