##### 314638669 | Barak10101998@gmail.com

# תכנות מערכות 2 מטלה 2  - גרפים
___


# תכנות מערכות 2 מטלה 1  - גרפים
___
הפעלה:
---
```make runDemo``` לקימפול והרצת הדמו:

```make runTest``` לקימפול והרצת הבדיקות:


`Graph.hpp` מימוש מחלקת הגרף
---
מחלקת הגרף היא מחלקה השומרת בתוכה מטריצת שכנויות ומורכבת מכמה פונקציות:

- `vector<vector<int>>& loadGraph(vector<vector<int>> matrix)` טעינת מטריצת השכנויות לאובייקט הגרף ובדיקה אם הקלט תקין 

- `void printGraph()` נדפיס את מספר הקודקודים והצלעות בגרף

- `bool isDirected()` נחזיר האם הגרף מכוון או לא מכוון

- `int getEdges()` נחזיר את מספר הצלעות בגרף

- `bool getisNegativeEdges()` נחזיר האם קיימות צלעות שליליות בגרף

- `void addS()` נוסיף לגרף קודקוד נוסף עם צלעות היוצאות ממנה לכל קודקוד בגרף

`Algorithms.hpp` מימוש מחלקת האלגוריתמים
---

מחלקת האלגוריתמים היא מחלקה המורכבת **מפונקציות סטטיות בלבד**, למלחלקה פונקציות סטטיות **פרטיות** המממשות 
אלגוריתמים ידועים על גרפים:


- `BellmanFord(Graph &g,int src)` מציאת מסלול קצר מקודקוד לשאר הקודקודים לצלעות בעלות משקל חיובי ושלילי
- `Dijkstra(Graph &g,int src)` מציאת מסלול קצר מקודקוד לשאר הקודקודים לצלעות בעלות משקל חיובי
- `DFS(Graph &g, stack<int> &orderOfVertices)` סריקת קודקודים לעומק
- `twoColoringGraph(Graph &g)` צביעת הגרף לשני צבעים
- `Transpose(Graph &g)` היפוך צלעות בגרף

למחלקה פונקציות סטטיות **ציבוריות** המשתמשות בפונקציות סטטיות הפרטיות:

`bool isConnected(Graph &g)`

פונקציה זו מומשה על פי אלגוריתם למציאת רכיבי קשירות חזקה בגרף. 
בעזרת אלגוריתם לסריקת קודקודים לעומק לפי סדר קודקודים מסוים.
כתוצאה מכך נקבל סדר יורד של קודקודים לפי זמני הסיום שלהם, 
נעשה היפוך צלעות
ונריץ שוב סריקת קודקודים לעומק לפי סדר הקודקוד שקיבלנו.
נבדוק אם מהתוצאה של הסריקה קיבלנו יער בעל עץ אחד, אם כן הגרף קשיר חזק.

`string shortestPath(Graph &g,int src,int dest)`

פונקציה זו מומשה בעזרת אלגוריתם למציאת מסלול קצר מקודקוד לשאר הקודקודים,
נבדוק אם לא קיימות צלעות שליליות ונריץ דייקסטרה, אם כן נריץ בלמן פורד. אם מצאנו מעגל שלילי נחזיר -1,
אם מצאנו מסלול קצר נחזיר את מסלול ואם לא, נחזיר -1 

`string isContainsCycle(Graph &g)`

פונקציה זו מומשה בעזרת אלגוריתם לסריקת קודקודים לעומק. באלגוריתם זה אם קיבלנו ״צלע אחורה״ (כאשר במהלך הסריקה נתקל בקודקוד אפור) האלגוריתם ישמור את שני הקוקודים.
אם קיבלנו צלע אחורה נחזיר את המעגל ואם לא, נחזיר 0

`string isBipartite(Graph &g)`

פונקציה זו מומשה בעזרת אלגוריתם לצביעת הגרף ל2 צבעים, כלומר אם הגרף 2-צביע אפשר לחלק אותו לגרף דו צדדי.
נחזיר את החלוקה אם אפשר ואם לא, נחזיר 0

`string negativeCycle(Graph g)`

פונקציה זו מומשה בעזרת האלגוריתם בלמן פורד המוצא גם אם קיים מעגל שלילי .
אם לא קיימות צלעות שליליות נחזיר 0.
אם קיימות
נקבל העתק של הגרף (ולא רפרנס) נוסיף לו קודקוד חדש המתחבר לכל הקודקודים בכיוון חד כיווני ממנו אליו עם משקל 0.
 נריץ בלמן פורד מהקודקוד החדש,
אם קיים מעגל שלילי נחזיר אותו ואם לא, נחזיר 0
