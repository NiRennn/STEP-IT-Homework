cmake_minimum_required(VERSION 3.25)
project(Project_OOP_FinanceManager)

set(CMAKE_CXX_STANDARD 20)

add_executable(Project_OOP_FinanceManager FinManager.cpp Wallet.cpp Wallet.h Expense.cpp Expense.h FinanceManager.cpp FinanceManager.h)
