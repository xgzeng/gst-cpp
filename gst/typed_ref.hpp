#pragma once
#include <glib-object.h>

namespace gst {

template<typename T>
class TypedRef {
public:
  TypedRef() : ptr_(nullptr) {
  }

  TypedRef(T* p)
  : ptr_(p) {
  }

  ~TypedRef() {
    if (ptr_) {
      g_object_unref(ptr_);
    }
  }

  // move constructor
  TypedRef(TypedRef&& other)
  : ptr_(other.ptr_) {
    other.ptr_ = nullptr;
  }

  // copy constructor
  TypedRef(const TypedRef& other)
  : ptr_(other.ptr_) {
    if (ptr_) {
      g_object_ref(ptr_);
    }
  }

  // copy operator
  TypedRef& operator=(const TypedRef& ref) {
    if (this == &ref) return *this;

    if (ptr_) {
      g_object_unref(ptr_);
    }

    ptr_ = ref.ptr_;

    if (ptr_) {
      g_object_ref(ptr_);
    }

    return *this;
  }

  T* get() const {
    return ptr_;
  }

  void SetProperty(const char* property_name, int value) {
    g_object_set(ptr_, property_name, value, nullptr);
  }

  void SetProperty(const char* property_name, const char* value) {
    g_object_set(ptr_, property_name, value, nullptr);
  }

private:
  T* ptr_;
};

} // namespace gst
