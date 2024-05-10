from simple_chalk import chalk, green
import subprocess
try: 
    # test = subprocess.check_output(["g++", "kinetic_test.cpp","-o","kinetic_test"])
    ans = subprocess.check_output(["./kinetic_test"], text=True)
    ans = ans[0:len(ans)-1].split("\n")
    actual_output = '''Key: 40, Data: 4
Key: 35, Data: 2
Key: 13, Data: 3
Key: 20, Data: 1
Key: 25, Data: 5
Max Node: Key = 40, Data = 4
Initial Heap:
Key: 40, Data: 4
Key: 35, Data: 2
Key: 13, Data: 3
Key: 20, Data: 1
Key: 25, Data: 5
Node to delete: 25
After deleting node with key 25:
Key: 40, Data: 4
Key: 35, Data: 2
Key: 13, Data: 3
Key: 20, Data: 1
Node to delete: 20
After deleting node with key 20:
Key: 40, Data: 4
Key: 35, Data: 2
Key: 13, Data: 3
Node to delete: 13
After deleting node with key 13:
Key: 40, Data: 4
Key: 35, Data: 2
Node to delete: 35
After deleting node with key 35:
Key: 40, Data: 4
Node to delete: 40
After deleting node with key 40:
Heap is empty
Node is nullptr
Node is nullptr
Heap after heapify down operation:
Heap is empty'''.split("\n")
    for i in range(len(ans)):
        if ans[i]==actual_output[i]:
            print(chalk.green.bold("[ Test Passed ]"))
        else:
            print(chalk.red.bold("[ Test Failed ]"))
            print("Expected Output:",actual_output[i])
            print("Actual Output:", ans[i])
except subprocess.CalledProcessError as e: 
    print(f"Command failed with return code {e.returncode}")