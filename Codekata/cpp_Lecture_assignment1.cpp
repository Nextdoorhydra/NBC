//#include <iostream>
//#include <vector>
//#include <map>
//#include <algorithm>
//
//using namespace std;
//
//struct Movie {
//    string title;
//    double rating;
//};
//
//class MovieProcessor {
//public:
//    virtual void process(vector<Movie>& processor) = 0;
//};
//
//
//// 기본 영화 관리자
//class MovieManager {
//private:
//    vector<Movie> movies;
//    map<string, double> movieMap;
//
//public:
//    MovieManager() {
//        // 초기 데이터 설정
//        movies = {
//            {"Inception", 9.0},
//            {"Interstellar", 8.6},
//            {"The Dark Knight", 9.1},
//            {"Memento", 8.4}
//        };
//
//        for (const auto& movie : movies) {
//            movieMap[movie.title] = movie.rating;
//        }
//    }
//
//    void printMovies() {
//        cout << "영화 목록:\n";
//        for (const auto& movie : movies) {
//            cout << "제목: " << movie.title << ", 평점: " << movie.rating << "\n";
//        }
//    }
//
//    void findMovie(const string& title) {
//        auto it = movieMap.find(title);
//        if (it != movieMap.end()) {
//            cout << "영화 제목: " << it->first << ", 평점: " << it->second << "\n";
//        }
//        else {
//            cout << "해당 영화는 목록에 없습니다.\n";
//        }
//    }
//
//    // MovieProcessor를 사용하여 기능 확장
//    void processMovies(MovieProcessor& processor) {
//        processor.process(movies);
//    }
//};
//
//
//// 내림차순
//bool compareMovies(vector<Movie>& a, vector<Movie>& b) {
//    if (a.empty() && !b.empty()) {
//        return false;
//    }
//    else if (b.empty() && !a.empty()) {
//        return true;
//    }
//    else if(a.empty() && b.empty()){
//        return false;
//    }
//    
//    double sumA = 0, sumB = 0;
//
//    for (int i = 0; i < a.size(); i++) {
//        sumA += a[i].rating;
//    }
//
//    for (int i = 0; i < a.size(); i++) {
//        sumA += b[i].rating;
//    }
//
//    return sumA / a.size() > sumB / b.size();
//}
//
//class RatingSorter : public MovieProcessor {
//public:
//    void process(vector<Movie>& movies) override {
//        sort(movies.begin(), movies.end(), compareMovies);
//    }
//};
//
//
//// 구체 클래스: 특정 평점 이상의 영화 필터링
//class RatingFilter : public MovieProcessor {
//private:
//    double minRating;
//
//public:
//    explicit RatingFilter(double minRating) : minRating(minRating) {}
//
//    void process(vector<Movie>& movies) override {
//        cout << "평점 " << minRating << " 이상인 영화 목록:\n";
//        for (const auto& movie : movies) {
//            if (movie.rating >= minRating) {
//                cout << "제목: " << movie.title << ", 평점: " << movie.rating << "\n";
//            }
//        }
//    }
//};
//
//int main() {
//    MovieManager manager;
//
//    cout << "1. 영화 목록 출력\n";
//    manager.printMovies();
//
//    cout << "\n2. 영화 검색 (예: Interstellar)\n";
//    manager.findMovie("Interstellar");
//
//    cout << "\n3. 평점 기준 정렬 및 출력\n";
//    RatingSorter sorter;
//    manager.processMovies(sorter);
//
//    cout << "\n4. 평점 8.5 이상인 영화 필터링 및 출력\n";
//    RatingFilter filter(8.5);
//    manager.processMovies(filter);
//
//    return 0;
//}
//
