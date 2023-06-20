**Computer Engineering Department**

**TED University**

**CMPE 326 Concepts of Programming Languages**

**Spring 2023**

**Homework 1**

**1. Introduction**

Most major websites collect feedback from their customers in order to improve the quality of their services. The most common form of user feedback is ratings. For example, Amazon.com collects users’ ratings of books, Imdb.com collects movie ratings and Booking.com gathers users’ rating of hotels.

A rating consists mainly of three important pieces of information:

1\. The user ID: this is the ID of the user who gave the rating.

2\. The item ID: this is the ID of the item being rated. For example, the item can be a book, a movie or a hotel.

3\. The rating value: this is a numerical value that is usually an integer ranging from 1 to 5, where 1 is the lowest rating (user not satisfied) and 5 is the highest rating (user very satisfied).

Your goal in this project is to write a program that reads a list of ratings, stores them in memory and answers a number of queries. Examples of queries are: What is the rating given by user *i* to item *j*? What is the average rating of item *j*? What is (are) the highest rated item(s)?

**2. Implementation**

In this assignment you are going to construct a Linked List (LL) to store the necessary data and manipulate it. The list consists of a head and a set of nodes. Each node in the LL stores user ID, item ID, and rating value. The head points to the first node if any and each node points to the subsequent node. The last nodes points to null.

The implementation language is C. Your implementation of LL should use dynamic data structures that heavily relies on pointers.

**3. Input/Output Specifications**

Your program should accept the set of commands from standard input.

**1) INSERT userID itemID value**

The INSERT command expects three numbers: userID, itemID, rating. It is assumed that a customer is eligible for a single rating for a particular item but he is allowed to update his rating for an item rated before. In case of a customer with a new item, the INSERT command creates a new node, places the node in the list and displays a message “Customer rating (**userID, itemID**) is added successful”. In case of a customer with a previously rated item, the command updates the rating value in the existing node and displays a message “Customer rating (**userID, itemID**) is updated”.

**2) REMOVE userID itemID**

The REMOVE command expects two integers: userID, itemID. It removes the rating for the user with userID and itemID form the list if it exists and displays a message “Customer rating (**userID**, **itemID**) is removed successful”. In case if the rating does not exits in the list, it displays a message “Customer rating (**userID, itemID**) does not exit”

**3) RATING userID itemID**

The **RATING** command takes the input values userID itemID, searches the user and displays a message “Customer rating (**userID, itemID**) is: **value**”. In case the rating is missing, the **value** should be displayed zero (0).

**4) AVERAGE itemID**

The **AVERAGE** command takes the input values itemID, and displays a message “Average rating (**itemID**) is: **value**”. In case the rating is missing, the **value** should be displayed zero (0).

**Note:** You can assume that there are no errors in the input. Hence, you do not need to explicitly check for correctness of the provided input.

*Here are some sample runs:*

> *INSERT 1 1 5*

> Customer rating (1, 1) is added successful

> *INSERT 1 2 1*

> Customer rating (1, 2) is added successful

> *INSERT 2 1 3.5*

> Customer rating (2, 1) is added successful

> *INSERT 2 2 5*

> Customer rating (2, 2) is added successful

> *RATING 2 1*

> Customer rating (2, 1) is: 3.5

> *RATING 2 3*

> Customer rating (2, 3) is: 0.0

> *INSERT 1 2 4*

> Customer rating (1, 2) is updated

> *AVERAGE 2*

> Average rating (2) is: 4.5

> *AVERAGE 3*

> Average rating (2) is: 0.0
