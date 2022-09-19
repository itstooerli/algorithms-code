## Problem Statement
Alice and Bob are planning to go to a restaurant to celebrate Alice’s birthday. Alice
chose a place from a list of restaurants (restaurantList), encrypted the name of this place using a ToyCrypt cipher, and then sent the encrypted name to Bob. Bob received the encrypted message. However, he does not know the encryption key, so he cannot decrypt the message. Your goal is to write a computer program that finds the key.

The ToyCrypt cipher uses keys that are integer numbers from 0 to n, where n is a parameter
which is less than 100000. Hence, you can find the key using the exhaustive search. In other words, you can try all possible keys from 0 to n and return the one that decrypts the message. To decrypt the message use function

> `std::string decrypt(const std::vector<int>& encryptedName, int key)`

which decrypts message `encryptedName` using key `key`. You can assume that the message is decrypted correctly if the resulting string is in the list of restaurants `restaurantList`.

Please, implement the following function

> `FindKey(const std::vector<int>& encryptedName, int n, const std::string& restaurantList)`

Function `FindKey` should return the key that was used by Alice to encode the restaurant name.

The arguments of the function are as follows:
* `const std::vector<int>& encryptedName` – the encrypted message

* `int n` – the maximum possible value of the key (i.e., the key must be an integer in the range
from 0 to n)

* `const std::string& restaurantList` – the list of restaurants separated by “;”
