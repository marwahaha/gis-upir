#pragma once

#include <iterator>

#include <boost/iterator/iterator_facade.hpp>

class default_sentinel :
    public boost::iterator_facade<default_sentinel, const int,
                                  std::forward_iterator_tag> {
 public:
  default_sentinel() = default;
  template <class It>
  default_sentinel(const It&) {}
  
 private:
  friend class boost::iterator_core_access;
 
  int dereference() const;
  
  void increment();
  template <class It>
  bool equal(const It& that) const {
    return that.equal(*this);
  }

};