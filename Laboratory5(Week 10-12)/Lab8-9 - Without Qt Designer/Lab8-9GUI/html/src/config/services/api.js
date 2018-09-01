// a library to wrap and simplify api calls
import apisauce from 'apisauce'

// our "constructor"
// http://localhost:8080/api is the address of the spring server
const create = (baseURL = 'http://localhost:8080/api') => {
  const api = apisauce.create({
    // base URL is read from the "constructor"
    baseURL,
    // here are some default headers
    headers: {
    },
    // 10 second timeout...
    timeout: 10240
  })

  return {
    // a list of the API functions
  }
}

export default {
  create
}
