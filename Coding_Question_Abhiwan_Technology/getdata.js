// Node js Program for Sorting , Searching and Segmentation.
async function fetchdata() {
    try {
        const response = await fetch('https://jsonplaceholder.typicode.com/todos/')
        const data = await response.json();
        return data;
    } catch (error) {
        console.error('Error fetching data:', error);
        return [];
    }
}
function sortdata_by_userid_id(data){
    return data.sort((a , b) =>{
        if(a.userID < b.userID){
            return 1;
        }
        else if(a.userID > b.userID){
            return -1; 
        }
        else{
            return a.id - b.id;
        }
    })
}
function searchData_by_id_userid(id , userID , data ){
    return data.find((x) => x.id == id && x.userId == userID)  
}
function createsegment(data){
    var segment = {}
    data.forEach(e => {
        if (!segment[e.userId]) {
            segment[e.userId] = [e]
        }else{
            segment[e.userId].push(e)
        }
    });
    return segment;
}

async function main() {
    const data = await fetchdata();
    console.log(data);
    const sorteddata = sortdata_by_userid_id([...data])
    console.log(sorteddata);
    const id = "1"; 
    const userId = "1";
    const searcheddata = searchData_by_id_userid(id , userId , data);
    console.log(searcheddata);
    const segmenteddata = createsegment(data)
    console.log(segmenteddata)
    
}
main()
