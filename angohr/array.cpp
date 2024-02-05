// SPDX-FileCopyrightText: Copyright contributors to the Angohr project
// SPDX-License-Identifier: BSD-3-Clause

module;

#include <algorithm>

export module core : iface.array;

namespace core {
export template <typename T>
class Array {
public:
  Array() = default;
  virtual ~Array() = default;

  unsigned int ref() { return m_ref; }

  unsigned int size() const { return m_count; }

  bool empty() const { return m_count == 0; }

  void push_back(T val);

  T front() {
    if (m_count > 0)
      return m_data[0];
    return 0;
  }

  T back() {
    if (m_count > 0)
      return m_data[m_count - 1];
    return 0;
  }

  T at(unsigned int idx) {
    if (idx < m_count)
      return m_data[idx];
    return 0;
  }


private:
  unsigned int m_ref = 1;
  unsigned int m_count = 0;
  unsigned int m_reserve = 0;
  T* m_data = nullptr;
};

template <typename T>
inline void Array<T>::push_back(T val)
{
  if ((m_count + 1) > m_reserve) {
    // Reallocate and copy the data.
    unsigned int newSize = 2;
    if (m_reserve > 2)
      newSize = m_reserve * 2;
    auto* newData = new T[newSize];
    if (m_reserve > 0)
      std::copy(m_data, m_data + m_count, newData);
    delete [] m_data;
    m_data = newData;
    m_reserve = newSize;
  }
  m_data[m_count++] = val;
}

}
