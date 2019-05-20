#!/usr/bin/env python3
from selenium import webdriver
from selenium.common.exceptions import NoSuchElementException
from selenium.common.exceptions import NoSuchWindowException
from selenium.common.exceptions import WebDriverException
from selenium.webdriver.support.ui import Select
from datetime import datetime
import time

def main():
    # Main ===============================================================================
    # Parameter Settings
    count = 0
    loop = True
    FurnishOption = "Unfurnished"#===============================
    case = 1
    start_time = 22#=========================
    end_time = 8#========================

    # Chrome driver opening
    driver = webdriver.Chrome()
    driver.get('https://assignments.housing.umich.edu/studentweb/')
    print("\n")

    Login(driver)
    """
    SelectApart(driver)
    FillInBlanks(driver, FurnishOption)
    """
    while loop == True:
        try:
            if case == 1:
                """
                Case 1 - Normal Case: checks the availability, outputs the result in terminal, and retry.
                """
                CheckAvailability(driver, count)
                count += 1

            elif case == 2:
                """
                Case 2 - Stuck in login page
                """
                print("\nWarning: Attempting case 2")
                Login(driver)
                case = 3

            elif case == 3:
                """
                Case 3 - Stuck in select apartment page
                """
                print("Warning: Attempting case 3")
                SelectApart(driver)
                case = 4
                
            elif case == 4:
                """
                Case 4 - Stuck in fill in information page
                """
                print("Warning: Attempting case 4\n")
                FillInBlanks(driver, FurnishOption)
                case = 1

            else:
                FillInBlanks(driver, FurnishOption)
                
        except NoSuchElementException:
            if case < 4:
                """
                Switch variable 'case' to try every scenario
                """
                case += 1

            else:
                """
                All scenarios are not applicable -> Housing found?!
                """
                try:
                    """
                    Test section. Haven't been verified on website.
                    """
                    driver.find_element_by_class_name("formLabel")

                except:
                    """
                    Any kind of exceptions.
                    """
                    #TODO
                    print("\n========================\n Something's wrong :(\n Restarting browser.....\n========================\n")
                    driver = webdriver.Chrome()
                    driver.get('https://assignments.housing.umich.edu/studentweb/')
                    loop = True
                    case = 2                

                else:
                    driver.save_screenshot('SucessfulScreenShot.png')
                    
                    source_code = driver.page_source
                    name = 'SucessfulSourceCode.html'
                    file = open(name, 'w', encoding = 'utf-8')
                    file.write(source_code)
                    file.close
                    
                    print("Housing Available:", datetime.now().strftime('%H:%M:%S'))
                    Alarm_youtube = driver.execute_script("window.open()")
                    driver.switch_to.window(driver.window_handles[1])
                    driver.get('https://www.youtube.com/watch?v=YPNvmxGDqks')
                    
                    loop = False

        except (NoSuchWindowException, WebDriverException) as WindowError:
            """
            Window disappearing.
            """
            print("!!!\nWarning: Window Reopen:  ", datetime.now().strftime('%H:%M:%S'), "\n!!!")
            driver = webdriver.Chrome()
            driver.get('https://assignments.housing.umich.edu/studentweb/')
            loop = True
            case = 2

        except KeyboardInterrupt:
            loop = False
            print("\n====================\n\n Keyboard Interrupt \n\n====================\n")

        else:
            if int(datetime.now().strftime('%H')) >= end_time and int(datetime.now().strftime('%H')) <= start_time:
                print("Time's up !!")
                driver.quit()
                loop = False
                
            else:
                pass
                
        finally:
            if loop == False:
                print("\n===============\n\n End of search \n\n===============\n")

def Login(driver):
    """
    Input ID and password at the Login webpage
    """
    Uniquename = driver.find_element_by_id("login")
    Uniquename.send_keys("")#=================================Your id
    password = driver.find_element_by_id("password")
    password.send_keys("")#==========================Your password
    password.submit()

def SelectApart(driver):
    """
    Press the 'Select an Apartment' button
    """
    SelectApartment = driver.find_element_by_link_text("Select an Apartment")
    SelectApartment.click()

def FillInBlanks(driver, furnishornot):
    """
    Fill in the blanks in the page before search result page.
    Variables:
    driver - chrome webdriver variable
    furnishornot - option of furnishing
    """
    Roommate = driver.find_element_by_id("chkRoommate172353")#==================not sure
    Roommate.click()

    IAmReady = Select(driver.find_element_by_id("fld31590"))
    IAmReady.select_by_visible_text("Yes")

    Furnishing = Select(driver.find_element_by_id("fld31591"))
    Furnishing.select_by_visible_text(furnishornot)

    StartDate = Select(driver.find_element_by_id("fld31589"))
    StartDate.select_by_visible_text("August 16")#=============================choose

    ArrivalDate = driver.find_element_by_id("dateflddtArrival")
    ArrivalDate.clear()
    ArrivalDate.send_keys("8/16/2019")#=========================================
    driver.find_element_by_id("btnSubmit").click()

def CheckAvailability(driver, count):
    """
    Finds if an "Error" class element is in the webpage and prints information and count.
    """
    driver.find_element_by_class_name("Error")
    count += 1
    print("Housing Unavailable(", count, "):", datetime.now().strftime('%H:%M:%S'))
        
    time.sleep(30)
    SearchAgain = driver.find_element_by_link_text("search")
    SearchAgain.click()

    driver.find_element_by_id("btnSubmit").click()

if __name__ == '__main__':

    main()