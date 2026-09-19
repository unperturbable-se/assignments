import socket
import threading
import math
import pickle

#grades=[90,86,82,78,74,70,66,62,58,54,50] 

def get_gpa(grade):
    gpa = 1.0+(math.floor((grade-50)/4)*(1/3))
    gpa=min(4,max(0,gpa))
    return round(gpa, 2)

def save_to_file(student):
    with open("cgpa_log.txt","ab") as f:
        pickle.dump(student,f)

def get_from_file():
    students=[]
    with open("cgpa_log.txt","rb") as f:
        while True:
            try:
                students.append(pickle.load(f))
            except EOFError:
                break
    for student in students: print(student)


def get_input(connection, message):
    connection.sendall(message.encode('utf-8'))
    message = connection.recv(1024).decode('utf-8')
    return message


def send_output(connection, message):
    connection.sendall(message.encode('utf-8'))


def singleThread(connection):
    send_output(connection, "Welcome to fast nuces  karachi campus gpa calculator!...(press enter to continue)\n")
    id = get_input(connection, "Enter your role number(24K-XXXX):")
    number_of_subjects = int( get_input(connection, "Enter the number of subjects:") )
    subjects = []
    sum = max = 0
    for i in range(number_of_subjects):
        name = (get_input(connection, f"Subject {i}:\nEnter the subject name"))
        credithour = int(get_input(connection, "Enter the credit Hour"))
        grade = int(get_input(connection, "Enter the grade(ie. 84)"))
        gpa=get_gpa(grade)
        subjects.append([name, credithour, gpa])
        max += credithour*4
        sum += credithour*gpa
    send_output(connection,f"Your cumulative GPA is: {(sum/max)*4}\n Press enter to exit")
    student={"Role number":id, "Sgpa":(sum/max)*4, "Subjects":subjects}
    save_to_file(student)
    send_output(connection,"Terminate")
    connection.close()


server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
server_socket.bind(('127.0.0.1', 65432))
server_socket.listen(30)
print("Server is listening on 127.0.0.1:65432...(press ctrl-c to exit)")

# Accept connections
try:
    while (True):
        connection, client_address = server_socket.accept()
        print(f"Connected to {client_address}")
        t = threading.Thread(target=singleThread, args=(connection,))
        t.start()
except KeyboardInterrupt:
    print("\nKeyboard interrupt entered: exiting....")
    print("FInal student logs...")
    get_from_file()
    server_socket.close()

