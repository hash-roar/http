#pragma once

class NonCopyable {
public:
    NonCopyable(const NonCopyable&) = delete;
    void operator=(const NonCopyable&) = delete;

protected:
    NonCopyable() = default;
    ~NonCopyable() = default;
};

class NonCopyMovable {
public:
    NonCopyMovable(const NonCopyMovable&) = delete;
    void operator=(const NonCopyMovable&) = delete;
    NonCopyMovable(NonCopyMovable&&) = delete;
    void operator=(NonCopyMovable&&) = delete;

protected:
    NonCopyMovable() = default;
    ~NonCopyMovable() = default;
};