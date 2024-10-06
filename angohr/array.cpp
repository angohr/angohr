// SPDX-FileCopyrightText: Copyright contributors to the Angohr project
// SPDX-License-Identifier: BSD-3-Clause

module;

#include <memory>
#include <vector>

export module core : iface.array;

namespace core {
export template <typename T>
class Array {
public:
  Array() : m_data(std::make_shared<std::vector<T>>()) {}

  /** Copy constructor */
  Array(const Array& other) : m_data(other.m_data) {}

  /** Move constructor */
  Array(Array&& other) noexcept : m_data(std::move(other.m_data)) {}

  /** Assignment operator */
  Array& operator=(const Array& other) {
    if (this != &other)
      m_data = other.m_data;
    return *this;
  }

  /** Move assignment operator */
  Array& operator=(Array&& other) noexcept {
    if (this != &other) {
      m_data = std::move(other.m_data);
      other.m_data = nullptr;
    }
  }

  virtual ~Array() = default;

  unsigned int ref() { return m_data.use_count(); }

  unsigned int size() const { return m_data->size(); }

  bool empty() const { return m_data->empty(); }

  void push_back(T val);

  T front() {
    if (size() > 0)
      return (*m_data)[0];
    return 0;
  }

  T back() {
    if (size() > 0)
      return m_data->back();
    return 0;
  }

  T at(unsigned int idx) {
    if (idx < size())
      return (*m_data)[idx];
    return 0;
  }

  const T& operator[](size_t idx) const {
    return (*m_data)[idx];
  }

  T& operator[](size_t idx) {
    if (ref() > 1)
      makeDeepCopy();
    return (*m_data)[idx];
  }

private:
  void makeDeepCopy() {
    m_data = std::make_shared<std::vector<T>>(*m_data);
  }

  std::shared_ptr<std::vector<T>> m_data;
};

template <typename T>
inline void Array<T>::push_back(T val)
{
  m_data->push_back(val);
}

}
