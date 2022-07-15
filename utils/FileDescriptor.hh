#pragma once
#include "NonCopyable.hh"
#include <cstddef>
#include <limits>
#include <memory>
#include <string>
class FileDescriptor : NonCopyMovable {
private:
    class FdWrapper {
    public:
        int fd_;
        bool eof_ = false;
        bool closed_ = false;
        unsigned read_count_ = 0;
        unsigned write_count_ = 0;

        explicit FdWrapper(const int fd);
        ~FdWrapper();
        void close();
    };

    std::shared_ptr<FdWrapper> internal_fd_;

    explicit FileDescriptor(std::shared_ptr<FdWrapper> other);

protected:
    void add_readcount() { ++internal_fd_->read_count_; }
    void add_writecount() { ++internal_fd_->write_count_; }

public:
    explicit FileDescriptor(const int fd);
    ~FileDescriptor() = default;

    std::string read(const size_t limit = std::numeric_limits<size_t>::max());

    void read(std::string& buf, const size_t limit = std::numeric_limits<size_t>::max());

    size_t write(const std::string &buf,const bool wait=true);

};