from threading import Thread, Lock, current_thread
from queue import Queue
import time

def worker(q, lock):
    while True:
        value = q.get()

        with lock:
            print(f'in {current_thread().name} got {value}')
        q.task_done()

if __name__ == '__main__':
    q = Queue()
    lock = Lock()

    num_threads = 10

    for i in range(num_threads):
        thread = Thread(target=worker, args=(q, lock))
        thread.daemon = True # daemon thread dies when main thread dies
        thread.start()

    for i in range(1, 21):
        q.put(i)

    q.join()

    # q.put(1)
    # q.put(2)
    # q.put(3)

    # # 3, 2, 1 -->
    # first = q.get()
    # print(first)

    # # q.empty()
    # q.task_done()
    # q.join()

    print("end main")
