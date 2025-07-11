function reverseIt(str, start, end) {
  let result = "";
  for (let i = end; i >= start; i--) {
    result += str[i];
  }
  return result;
}

function reverseTheString(st) {
  let start = 0, end = 0, result = "";
  while (end < st.length) {
    if (st[end] === " " || end === st.length - 1) {
      result += reverseIt(st, start, end);
      if (end != st.length - 1) result += " "
      start = end + 1;
    }
    end++;
  }
  return result;
}

const ans = reverseTheString("Hello Arush Sharma")
