/* python snippet */

def is_Anagram(Str1, Str2): 
    sorted1 = sorted(Str1.lower())
    sorted2 = sorted(Str2.lower())
    if sorted1 == sorted2: return True
    else: return False
