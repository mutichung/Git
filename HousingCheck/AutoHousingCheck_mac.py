from selenium import webdriver
#from selenium.common.exceptions import TimeoutException
from selenium.common.exceptions import NoSuchWindowException
from selenium.common.exceptions import NoSuchElementException
from selenium.common.exceptions import WebDriverException
#from selenium.webdriver.support.ui import WebDriverWait
#from selenium.webdriver.support import expected_conditions as EC
from selenium.webdriver.support.ui import Select
from selenium.webdriver.common.keys import Keys

from datetime import datetime
import time

DoItAgain = True
count = 0
driver = webdriver.Chrome()

# Open Website
driver.get('https://assignments.housing.umich.edu/studentweb/')

# Login
Uniquename = driver.find_element_by_id("login")
Uniquename.send_keys("mtchung")
password = driver.find_element_by_id("password")
password.send_keys("Honeybooboo850102")
password.submit()

# Get into "Select an apartment"
SelectApartment = driver.find_element_by_link_text("Select an Apartment")
SelectApartment.click()

# Settle Everything
Roommate = driver.find_element_by_id("chkRoommate172353")
Roommate.click()

IAmReady = Select(driver.find_element_by_id("fld31590"))
IAmReady.select_by_visible_text("Yes")

Furnishing = Select(driver.find_element_by_id("fld31591"))
Furnishing.select_by_visible_text("Unfurnished")

StartDate = Select(driver.find_element_by_id("fld31589"))
StartDate.select_by_visible_text("August 16")

ArrivalDate = driver.find_element_by_id("dateflddtArrival")
ArrivalDate.clear()
ArrivalDate.send_keys("8/16/2019")
driver.find_element_by_id("btnSubmit").click()
time.sleep(5)

# Check Avalaibility
while DoItAgain == True:
    try:    # Ordinary Case: no available housing found
        driver.find_element_by_class_name("Error")
        count += 1
        print("Housing Unavailable(", count,"):", datetime.now().strftime('%H:%M:%S'))
        
        if int(datetime.now().strftime('%H')) >= 8 and int(datetime.now().strftime('%H')) < 20:
            driver.quit()
            break
        else:
            pass
        
        time.sleep(30)
        SearchAgain = driver.find_element_by_link_text("search")
        SearchAgain.click()

        DoItAgain = True

        driver.find_element_by_id("btnSubmit").click()

    except NoSuchElementException:
        try:    # Webpage shut down??
            Uniquename = driver.find_element_by_id("login")
            Uniquename.send_keys("mtchung")
            password = driver.find_element_by_id("password")
            password.send_keys("Honeybooboo850102")
            password.submit()

            # Get into "Select an apartment"
            SelectApartment = driver.find_element_by_link_text("Select an Apartment")
            SelectApartment.click()

            # Settle Everything
            Roommate = driver.find_element_by_id("chkRoommate172353")
            Roommate.click()

            IAmReady = Select(driver.find_element_by_id("fld31590"))
            IAmReady.select_by_visible_text("Yes")

            Furnishing = Select(driver.find_element_by_id("fld31591"))
            Furnishing.select_by_visible_text("Unfurnished")

            StartDate = Select(driver.find_element_by_id("fld31589"))
            StartDate.select_by_visible_text("August 16")

            ArrivalDate = driver.find_element_by_id("dateflddtArrival")
            ArrivalDate.clear()
            ArrivalDate.send_keys("8/16/2019")
            driver.find_element_by_id("btnSubmit").click()
            print("!!!\nWarning: Window Reopen   ", datetime.now().strftime('%H:%M:%S'), "\n!!!")

        except NoSuchElementException:
            driver.save_screenshot('SucessfulScreenShot.png')
            
            source_code = driver.page_source
            name = 'SucessfulSourceCode.html'
            file = open(name, 'w', encoding = 'utf-8')
            file.write(source_code)
            file.close
            
            print("Housing Available:", datetime.now().strftime('%H:%M:%S'))
            Alarm_youtube = driver.execute_script("window.open()")
            driver.switch_to_window(driver.window_handles[1])
            driver.get('https://www.youtube.com/watch?v=YPNvmxGDqks')
            
            DoItAgain = False
            #time.sleep(999999)
            #break

    except NoSuchWindowException:
        driver = webdriver.Chrome()
        driver.get('https://assignments.housing.umich.edu/studentweb/')
        DoItAgain = True
    else:
        pass