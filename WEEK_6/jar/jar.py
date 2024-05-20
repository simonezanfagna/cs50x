class Jar:
    def __init__(self, capacity=12):
        self.capacity = capacity
        self.size = 0

    def __str__(self):
        return "🍪" * self.size

    def deposit(self, n):
        if self.size + n > self.capacity:
            raise ValueError("deposit error")
        else:
            self.size += n

    def withdraw(self, n):
        if n > self.size:
            raise ValueError("withdraw error")
        else:
            self.size -= n

    @property
    def capacity(self):
        return self._capacity

    @capacity.setter
    def capacity(self, capacity):
        if capacity < 1:
            raise ValueError("capacity error")
        else:
            self._capacity = capacity

    @property
    def getSize(self):
        return self.size

def main():

    jar = Jar(40)
    jar.deposit(3)
    print('capacity: ', str(jar.capacity))
    jar.withdraw(1)
    print(str(jar))
    jar.capacity = 400
    print('capacity: ',str(jar.capacity))

    print('size ',str(jar.getSize))

main()

