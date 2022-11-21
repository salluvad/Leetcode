class Solution {
    const static int encoding_bits = 6;
    
    const string alphabet = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    const string prefix = "https://tinyurl.com/";
    
    const int alphabet_size = alphabet.size();
    
    string key = get_rand();
    
    unordered_map<string, string> map;
    
    string get_rand() {
      /*  // https://en.cppreference.com/w/cpp/numeric/random/uniform_int_distribution
        mt19937 rng((random_device())());
        uniform_int_distribution<int> unif(0, alphabet_size - 1);
      */
        
        srand((unsigned) time(NULL));

	   // Get a random number and construct a string of tiny urls
	 
        stringstream ss;
        
       // for (int i = 0; i < encoding_bits; i++) ss << alphabet[unif(rng)];
         for (int i = 0; i < encoding_bits; i++) ss << alphabet[rand()%62];
        
        cout << ss.str();
        return ss.str();
    }
public:
    string encode(string longUrl) {
        while (map.count(key)) key = get_rand();
		
        map[key] = longUrl;
		
        return prefix + key;
    }

    string decode(string shortUrl) {
        /// rfind gives the posotion of last occurance of the char specified
        int position = shortUrl.rfind('/') ;
        return map[shortUrl.substr(position + 1)];   // get the 6 char endoded key part  of >> "http://tinyurl.com/4e9iAk"
    }
};
