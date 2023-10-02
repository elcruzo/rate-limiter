# ElCruzo's Rate Limiter

A simple rate limiter implemented in C++ using a token bucket algorithm. This rate limiter allows you to control the rate at which requests are allowed based on a specified rate and burst size.

## Features

- Implements a token bucket rate limiting algorithm.
- Allows you to control the rate (requests per second) and burst size.
- Ensures that requests are allowed at the specified rate while maintaining burst capacity.

## Usage

1. Clone the repository to your local machine:

   ```bash
   git clone https://github.com/elcruzo/rate-limiter.git
   cd rate-limiter
   ```

2. Build the C++ application (ensure you have a C++ compiler installed):

   ```bash
   g++ my_limiter.cpp -o rate_limiter
   ```

3. Run the application:

   ```bash
   ./rate_limiter
   ```

4. The program will simulate requests and print whether each request is allowed or rate-limited.

## Example

Here's an example of how to use the rate limiter:

```cpp

RateLimiter limiter(2, 5);

for (int i = 0; i < 10; i++) {
    if (limiter.allow()) {
        cout << "Request " << i << " is allowed." << endl;
    } else {
        cout << "Request " << i << " is rate limited." << endl;
    }
    this_thread::sleep_for(chrono::milliseconds(500)); // Sleep for 500 milliseconds between requests
}
```

## License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.

## Contributions

Contributions are welcome! If you'd like to contribute to this project, please fork the repository and create a pull request.

## Contact

If you have any questions or suggestions, feel free to contact me at ayomideadekoya266@gmail.com.

```
