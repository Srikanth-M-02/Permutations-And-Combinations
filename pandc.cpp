#include <iostream>
#include <vector>
#include <algorithm>

template <typename T>
bool is_same(std::vector<T> &l1, std::vector<T> &l2)
{
  std::sort(l1.begin(), l1.end());
  std::sort(l2.begin(), l2.end());
  return l1 == l2;
}

template <typename T>
std::ostream &operator<<(std::ostream &os, const std::vector<T> &l)
{
  os << "{ ";
  for (auto &i : l)
    os << i << ", ";
  os << '}';
  return os;
}

template <typename T>
std::vector<std::vector<T>> &_permutations(const std::vector<T> &vec, std::vector<std::vector<T>> &perms, size_t n)
{
  if (n == 0)
    n = vec.size();
  if (perms.size() == 0)
  {
    for (auto &i : vec)
      perms.push_back(std::vector<T>{i});
    return _permutations(vec, perms, n);
  }

  else if (perms[0].size() == n)
    return perms;
  else
  {
    std::vector<std::vector<T>> newperms;
    for (auto i = perms.begin(); i != perms.end(); i++)
    {
      for (auto &j : vec)
      {
        if (std::find((*i).begin(), (*i).end(), j) == (*i).end())
        {
          std::vector<T> temp = *i;
          temp.push_back(j);
          newperms.push_back(temp);
        }
      }
    }
    perms = newperms;
    return _permutations(vec, perms, n);
  }
}

template <typename T>
std::vector<std::vector<T>> permutations(const std::vector<T> &vec, size_t n = 0)
{
  auto perms = std::vector<std::vector<T>>();
  return _permutations(vec, perms, n);
}

template <typename T>
std::vector<std::vector<T>> combinations(const std::vector<T> &vec, size_t n = 0)
{
  auto perms = std::vector<std::vector<T>>();
  perms = _permutations(vec, perms, n);
  for (size_t i = 0; i<perms.size(); i++)
    for (size_t j = i + 1; j<perms.size();)
      if (is_same(perms[i], perms[j]))
        perms.erase(perms.begin()+j);
      else
        j++;
  return perms;      
}

int main(int argc, char const *argv[])
{
  std::vector<int> l{1, 2, 3, 4};
  std::cout << permutations(l, 3);
  std::cout<<std::endl;
  std::cout << combinations(l, 3);
  return 0;
}
