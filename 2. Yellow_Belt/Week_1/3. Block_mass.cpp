#include <iostream>
#include <vector>

int main()
{
    int N, R, W, H, D, M = 0;
    std::cin >> N >> R;

    for (size_t i = 0; i < N; i++)
    {
        std::cin >> W >> H >> D;
        M += static_cast<uint64_t>(W) * H * D * R;
    }

    std::cout << "\n" << M;

    return 0;
}