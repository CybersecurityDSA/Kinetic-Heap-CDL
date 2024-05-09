from simple_chalk import chalk, green
import subprocess
try: 
    ans = subprocess.check_output(["g++", "cdl_test.cpp","-o","cdl_test"], text=True)
    ans = subprocess.check_output(["./cdl_test"], text=True)
    ans = ans[0:len(ans)-1].split("\n")
    actual_output = '''Initial list: 20 30 40 50 60 70 80 
Inserted 90 at end: 20 30 40 50 60 70 80 90 
Insert 10 at beginning: 10 20 30 40 50 60 70 80 90 
Delete from front: 20 30 40 50 60 70 80 90 
List before deletion (Deletion from back): 20 30 40 50 60 70 80 90 
Delete from back: 20 30 40 50 60 70 80 
List before deletion: 20 30 40 50 60 70 80 
Delete 70 (middle element): 20 30 40 50 60 80 
Delete 20 (first element): 30 40 50 60 80 
Forward traversal: 30 40 50 60 80 
Backward traversal: 80 60 50 40 30 
Node found with value 80
Node not found with value 100
List is empty: false
Size of the list: 5'''.split("\n")
    for i in range(len(ans)):
        if ans[i]==actual_output[i]:
            print(chalk.green.bold("[ Test Passed ]"))
        else:
            print(chalk.red.bold("[ Test Failed ]"))
            print("Expected Output:",actual_output[i])
            print("Actual Output:", ans[i])
except subprocess.CalledProcessError as e: 
    print(f"Command failed with return code {e.returncode}")