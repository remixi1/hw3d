#include "HwTimer.h"

using namespace std::chrono;

HwTimer::HwTimer() noexcept
{
	last = steady_clock::now();
}

float HwTimer::Mark() noexcept
{
	const auto old = last;
	last = steady_clock::now();
	const duration<float> frameTime = last - old;
	return frameTime.count();
}

float HwTimer::Peek() const noexcept
{
	return duration<float>(steady_clock::now() - last).count();
}