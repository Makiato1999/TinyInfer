#include <map>
#include <memory>
#include "base.h"

namespace base {
enum class MemcpyKind {
  kMemcpyCPU2CPU = 0,
  kMemcpyCPU2CUDA = 1,
  kMemcpyCUDA2CPU = 2,
  kMemcpyCUDA2CUDA = 3,
};

class DeviceAllocator {
 public:
    explicit DeviceAllocator(DeviceType device_type) : device_type_(device_type) {}
    
    virtual DeviceType device_type() const { return device_type_; }

    // 需要释放的内存，把这个地址对应的内存/显存释放掉
    virtual void release(void* ptr) const = 0;

    // 需要申请的内存/显存字节数，返回这块内存/显存的地址
    virtual void* allocate(size_t byte_size) const = 0;

    virtual void memcpy(const void* src_ptr, void* dest_ptr, size_t byte_size,
                      MemcpyKind memcpy_kind = MemcpyKind::kMemcpyCPU2CPU, void* stream = nullptr,
                      bool need_sync = false) const;

    virtual void memset_zero(void* ptr, size_t byte_size, void* stream, bool need_sync = false);

 private:
    DeviceType device_type_ = DeviceType::kDeviceUnknown;
};

class CPUDeviceAllocator : public DeviceAllocator {
 public:
    explicit CPUDeviceAllocator();

    void* allocate(size_t byte_size) const override;

    void release(void* ptr) const override;

    void memcpy(const void* src_ptr, void* des_ptr, size_t size, ) const override;
};

}  // namespace base